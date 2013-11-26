int checkUpper(uint8_t *field, int position){
  if(position-fieldWidth>0){
    if(field[position-fieldWidth]){
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    return 0;
  }
  return 0;
}
 
int checkLower(uint8_t *field, int position){
  if(position+fieldWidth<fieldSize){
    if(field[position+fieldWidth]){
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    return 0;
  }
  return 0;
}
 
int checkLeft(uint8_t *field, int position){
  if(position-1>0){
    if(field[position-1]){
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    return 0;
  }
  return 0;
}
 
int checkRight(uint8_t *field, int position){
  if(position+1<fieldSize){
    if(field[position+1]){
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    return 0;
  }
  return 0;
}
 
int checkUpperLeft(uint8_t *field, int position){
  if(position-fieldWidth+1>0){
    if(field[position-fieldWidth+1]){
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    return 0;
  }
  return 0;
}
 
int checkUpperRight(uint8_t *field, int position){
  if(position-fieldWidth-1>0){
    if(field[position-fieldWidth-1]){
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    return 0;
  }
  return 0;
}
 
int checkLowerLeft(uint8_t *field, int position){
  if(position+fieldWidth-1<fieldSize){
    if(field[position+fieldWidth-1]){
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    return 0;
  }
  return 0;
}
 
int checkLowerRight(uint8_t *field, int position){
  if(position+fieldWidth+1<fieldSize){
    if(field[position+fieldWidth+1]){
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    return 0;
  }
  return 0;
}
int totalAround(uint8_t *field, int position){
  int around = checkUpper(field, position)+checkLower(field, position)+checkLeft(field, position)+checkRight(field, position)+checkUpperLeft(field, position)+checkUpperRight(field, position)+checkLowerLeft(field, position)+checkLowerRight(field, position);
  return around;
}
