def convertSnakeModes(pattern, width, height):
	for y in range(0,height,2):
		tempList = []
		for x in range(width-1,-1,-1):
			tempList.append(pattern[y*width+x])
		for x in range(0, width):
			pattern[y*width+x] = tempList[x]
	return pattern
