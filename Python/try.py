def listPrint(abc):
	"""  """
	for i in xrange(len(abc)):
		print abc[i]

def insSort(arr):
	""" INSERTION SORT """
	j=len(arr)
	for pivot in xrange(1,j):
		for comp in xrange(0,pivot):
			if arr[pivot]<=arr[comp]:
				arr.insert(comp,arr[pivot])
				del arr[pivot+1]						
	

def mergeSort(arr):
	l=len(arr)
	if(l==1):
		return arr
	else:	
		arr1=mergeSort(arr[:(l/2)])
		arr2=mergeSort(arr[(l/2):])
		arr3=[]
		l1=len(arr1)
		l2=len(arr2)
		j=0
		k=0
		for i in xrange(l1+l2):
			if(j==l1):
				arr3[i:]=arr2[k:]
				break
			elif(k==l2):
				arr3[i:]=arr1[j:]	
				break
			else:
				if arr1[j]<=arr2[k] :
					arr3.append(arr1[j])
					j+=1
				else:
					arr3.append(arr2[k])
					k+=1
		return arr3

def linearSearch(arr,ele):
	lengg=len(arr)
	i=0
	for i in range(0,lengg):
		if (arr[i]==ele):
			return i
	return -1	

def binarySearch(arr,ele,left=0):
	arrLength=len(arr)
	if (arrLength!=1):
		if (arr[arrLength/2]==ele):
			if(left!=-1):
				return left+int(arrLength/2)
			else:
				return int(arrLength/2)
		elif(arr[int(arrLength/2)]<ele):
			ret=binarySearch(arr[int(arrLength/2):],ele,left+int(arrLength/2))
			if ret!= -1:
				return ret
		else:
			ret=binarySearch(arr[:int(arrLength/2)],ele,left)
			if ret!= -1:
				return ret

	else:
		if (arr[0]==ele):
			return left
	return -1

abc=[]
j=int(raw_input())

for i in range(j):
	abc.append(int(raw_input()))

listPrint(abc)
abc2=abc
insSort(abc)
print 'INS SORT :'
listPrint(abc)
print 'MERGE SORT :'
abc2=mergeSort(abc2)
listPrint(abc2)
print 'Linear Search :Found at:',linearSearch(abc2,345689)+1,'th position'
print 'Binary Search :Found at:',binarySearch(abc2,345689)+1,'th position'

