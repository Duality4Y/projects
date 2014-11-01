#include <unistd.h>
#include <apr_errno.h>
#include <apr_file_io.h>

/*this file holds database code*/

#include "db.h"
#include "bstrlib.h"
#include "dbg.h"

static FILE *DB_open(const char *path, const char *mode)
{
	return fopen(path, mode);
}

static void DB_close(FILE *db)
{
	fclose(db);
}

static bstring DB_load()
{
	FILE *db = NULL;
	bstring data = NULL;//creates a bstring structure that contains a char * to the string. mlen and slen, for keeping track of things.
	
	db = DB_open(DB_FILE, "r"); //open file for reading only
	check(db, "Failed to read from db file: %s", DB_FILE);
	
	data = bread((bNread)fread, db);//will read data from the fread function.
	check(data, "Failed to read from db file: %s", DB_FILE);
	
	DB_close(db);
	return data; //return a pointer to bstring data. or our loaded data.
	
	error:
		if(db) DB_close(db);
		if(data) bdestroy(data);//destroy the bstring (data) structure. freeing it's members.
		return NULL;
}

int DB_update(const char *url)
{
	if(DB_find(url))
	{
		log_info("Already recorded as installed: %s", url);
	}//also if url exist this way it will still be added. so it exist twice and after that three times.
	
	FILE *db = DB_open(DB_FILE, "a+");//open file and be able to read, and append to it.
	check(db, "Failed to open DB file: %s", DB_FILE);
	
	bstring line = bfromcstr(url); //bfromcstr(url) creates a bstring structure that contains for char * url.
	bconchar(line, '\n'); //then concatenate a newline to the end of the data member.
	int rc = fwrite(line->data, blength(line), 1, db); //append this line to the end of the file. (db file)
	check(rc == 1, "Failed to append to the db.");
	//bfromcstr() uses malloc and there for must be freed ?
	return 0;
	
	error:
		if(db) DB_close(db);
		return -1;
}

int DB_find(const char *url)
{
	bstring data = NULL;
	bstring line = bfromcstr(url);//create a bstring and put the url in it.
	int res = -1;
	
	data = DB_load();
	check(data, "Failed to load: %s", DB_FILE);
	//looke for url in the data in the database file.
	//starting at the first char in data base file.
	//if BSTR_ERR is returned. it's not present.
	if(binstr(data, 0, line) == BSTR_ERR)
	{
		res = 0;
	}
	else
	{
		res = 1;
	}
	//yet here bstring line is freed after it used bfromcstr(url);
	//unlike in the function DB_update
	
	//and fallthrough because 0 is not found.
	//1 is found. and it doesn't matter for the function to return an err.
	//because it can't because it will only do one of these, and return ?
	error: //fall through.
		if(data) bdestroy(data);
		if(data) bdestroy(line); //destroy the bstring with the url in it.
		return res;//return wether it's found or not.
}

int DB_init()
{
	apr_pool_t *p = NULL;//fundametal pool type.
	apr_pool_initialize();//setup all of the internal structures required to use pools
	apr_pool_create(&p, NULL); //&p because it wants a pointer to pointer, and NULL for no parrents.
	//alright still don't know what a apr pool is.
	//oh google reveals to me that apr pool is a memory allocation system/s.
	//and further investigation reveals to me that it's a resource management system,
	//like in the manor of malloc.
	
	//access() is used to check file permissions
	//with W_OK | X_OK we test wether  we have write and execute permisions.
	if(access(DB_DIR, W_OK|X_OK) == -1)
	{
		apr_status_t rc = apr_dir_make_recursive(DB_DIR,
			APR_UREAD|APR_UWRITE|APR_UEXECUTE|
			APR_GREAD|APR_GWRITE|APR_GEXECUTE, p);
		/*
		 * creates a new director on the files system,
		 * behave like mkdir -p.
		 * basicly recursive, and can make a folder in a folder etc.
		 * and the second argument is/are the permisions for the new directory.
		 * */
		check(rc == APR_SUCCESS, "Failed to make database dir: %s", DB_DIR);
	}
	//see if we got write permissions.
	if(access(DB_FILE, W_OK) == -1)
	{
		FILE *db = DB_open(DB_FILE, "w");//open file for writing.
		check(db, "Cannot open database: %s", DB_FILE);
		DB_close(db);//and close it again ?
		//and then what ? what's the point ?
	}
	
	apr_pool_destroy(p); //free the pool. also on error.
	return 0;
	
	error:
		apr_pool_destroy(p);
		return -1;
}

int DB_list()
{
	//load data base file as string into bstring data.
	bstring data = DB_load();
	check(data, "Failed to read load: %s", DB_FILE);
	
	printf("%s", bdata(data)); //print every line in it.
	bdestroy(data);//free the bstring.
	return 0;
	error:
		return -1;
}
