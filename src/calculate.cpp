/*
 * =====================================================================================
 *
 *       Filename:  calculate.cpp
 *
 *    Description:  real calculate cpp file.
 *
 *        Version:  1.0
 *        Created:  2016/08/31 18时16分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  XadillaX (zkd), i@2333.moe
 *   Organization:  Design & Development Center, Souche Inc. CHINA
 *
 * =====================================================================================
 */
#include "calculate.h"
#include <cstdlib>
#include <openssl/md5.h>

string RealCalculateLeblancMD5(const char* filename, char md5[17])
{
    FILE* in_file = fopen(filename, "rb");
    if(NULL == in_file)
    {
        string error = filename;
        error += " can't be opened.";
        return error;
    }

    int bytes;
    unsigned char c[16];
    unsigned char data[1024];
    MD5_CTX md_context;
    MD5_Init(&md_context);
    while((bytes = fread(data, 1, 1024, in_file)) != 0)
    {
        MD5_Update(&md_context, data, bytes);
    }
    MD5_Final(c, &md_context);
    sprintf(md5,
            "%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
            c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7], c[8], c[9], c[10],
            c[11], c[12], c[13], c[14], c[15]);

    return "";
}
