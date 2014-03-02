import os
assembler_file_path = "/home/robert/projects/python_assembler/"
assembler_file = open(assembler_file_path+"build.s", "r")
newFile = open(assembler_file_path+"build.s"+".parse", "w");
assembler_instructions = open(assembler_file_path+"ASM_INSTRUCTIONS", "r");
newInstructFile = open(assembler_file_path+"asm_instruct.pars", "w");

#this is because i dissassembled one of my own source files for testing.
def stripBogus(line):
	line = line.split('\t');
	del line[0:2]
	line = ' '.join(line)
	return line

"""
for everyline in assembler_file:
	newLine = stripBogus(everyline)
	if newLine.find(".word") == -1:
		print newLine
		newFile.write(newLine);
"""
newInstruct = ""
for i,line in enumerate(assembler_instructions):
	templine = ''.join(line.split('  ')[1]).strip('\r\n ')
	newInstruct += "\""+templine+"\": ,\n"

print newInstruct
newInstructFile.write(newInstruct);
newInstructFile.close();
assembler_instructions.close();
assembler_file.close();
newFile.close();
