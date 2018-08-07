#include<iostream>
#include<stdlib.h>
//DELETE_ARRAY参数中传n
#define NEW_ARRAY(ptr,type,n)						   \
do{														\
	ptr = (type*)operator new(sizeof(type)*n);			\ 
														\
for (size_t i = 0; i < n; ++i)							\
{														\
new(ptr + i)type;										\
}														\
} while (0);											\


#define DELETE_ARRAY(ptr,type,n)						\
do{														\
														\
														\
for (size_t i = 0; i < n; ++i)							\
{														\
	(ptr + i)->~String();								\
}														\
	operator delete ptr;								\
} while (0);


//给DELETE_ARRAY中不传n
#define NEW_ARRAY(ptr,type,n)							\
do{															\
															\
	ptr = (type*)operator new(sizeof(type)*n + 4);			\  //给n也分配空间
*(int*)ptr = n;												\
ptr=(type*)((char*)ptr+4);									\
for (size_t i = 0; i < n; ++i)								\
{															\
new(ptr + i)(type);									\
}															\
} while (0);

#define DELETE_ARRAY(ptr,type)								\
do{																\
															\
	\
	size_t n = *((int*)ptr - 1);							\
	\
	for (size_t i = 0; i < n; ++i)								\
	{															\
	(ptr + i)->~String();									\
	}															\
	operator delete(char*(ptr - 4));							\
} while (0);


