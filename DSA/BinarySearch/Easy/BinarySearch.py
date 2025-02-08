def binarySearch(arr,target):
    left=0
    right=len(arr)-1
    
    while left<=right:
        mid=left+(right-left)//2
        
        if(arr[mid] < target):
            left=mid+1
        
        elif(arr[mid] > target):
            right=mid-1
        
        else:
            return mid

    return -1

        

arr=[1,2,3,4,5,6,7,8,9,10]
target=5
print(binarySearch(arr,target))

