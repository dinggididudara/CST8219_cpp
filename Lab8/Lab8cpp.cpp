

#include "Lab8java.h" // will  include "JNI.h"
#include <iostream>
#include <omp.h>

using namespace std;

static double mean = 0;
static double a = 0;
static double sd = 0; 


JNIEXPORT jdouble JNICALL Java_Lab8java_calculateMean(JNIEnv* env, jobject caller,jintArray arr)
{
    int len = env->GetArrayLength(arr);//Returns the number of elements in the array arr.

    cout << "Calculating Mean..." << endl;
    
    jint* elements = (env)->GetIntArrayElements(arr, NULL);// Returns a pointer to the array elements, or�NULL�if the operation fails.

#pragma omp parallel for reduction(+: mean)
    for(int i=0;i<len;i++)
    {
        mean += elements[i];
    }
#pragma omp barrier
    env->ReleaseIntArrayElements(arr, elements, 0);//The result is valid until the corresponding�ReleaseInt ArrayElements()�function is called.

    return mean;
}


JNIEXPORT jdouble JNICALL Java_Lab8java_calculateSTDDev(JNIEnv* env, jobject caller, jintArray arr)
{
    int len = env->GetArrayLength(arr);//Returns the number of elements in the array arr.

    cout << "Calculating Standard Deviation..." << endl;
    

    jint* elements = (env)->GetIntArrayElements(arr, NULL);// Returns a pointer to the array elements, or�NULL�if the operation fails.


#pragma omp parallel for reduction(+: mean)
    for (int i = 0; i < len; i++)
    {
        mean += elements[i];
    }
    mean = mean / len;

#pragma omp parallel for reduction (+: a)
    for (int i = 0; i < len; i++)
    {
        a += elements[i];
    }
    sd = sqrt(a / (len - 1.0));

#pragma omp barrier
    env->ReleaseIntArrayElements(arr, elements, 0);//The result is valid until the corresponding�ReleaseInt ArrayElements()�function is called.

    return sd;
}