#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include <string.h>
static int isValidUserId(int userId);
static int isValidName(char* name);
static int isValidEmail(char* email);


User* user_new(void)
{
    return (User*)malloc(sizeof(User));
}

User* user_newParametros(int userId,char* name,char* email)
{
    User* this=user_new();
    if(this!=NULL ||
        user_setUserId(this,userId) ||
        user_setName(this,name) ||
        user_setEmail(this,email))
    {
        user_delete(this);
        this=NULL;
    }
    return this;
}

void user_delete(User* this)
{
    free(this);
}

int user_setUserId(User* this,int userId)
{
    int retorno=-1;
    if(this !=NULL && !isValidUserId(userId))
    {

       this->userId=userId;
        retorno=0;
    }
    return retorno;
}

int user_getUserId(User* this,int* userId)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *userId=this->userId;
        retorno=0;
    }
    return retorno;
}

static int isValidUserId(int userId)
{
    int retorno=-1;
    if(userId>-1)
    {
        retorno=0;
    }
    return retorno;
}

int user_setName(User*this,char* name)
{
    int retorno=-1;
    if(this !=NULL && !isValidName(name))
    {
        strcpy(this->name,name);
        retorno=0;
    }
    return retorno;
}

int user_getName(User*this,char* name)
{
    int retorno=-1;
    if(this !=NULL)
    {
        strcpy(name,this->name);
        retorno=0;
    }
    return retorno;
}

static int isValidName(char* name)
{
    int retorno=-1;
    if(name!=NULL)
    {
        retorno=0;
    }
    return retorno;
}

int user_setEmail(User*this,char* email)
{
    int retorno=-1;
    if(this !=NULL && !isValidEmail(email))
    {
        strcpy(this->email,email);
        retorno=0;
    }
    return retorno;
}

int user_getEmail(User*this,char* email)
{
    int retorno=-1;
    if(this !=NULL)
    {
        strcpy(email,this->email);
        retorno=0;
    }
    return retorno;
}

static int isValidEmail(char* email)
{
    int retorno=-1;
    if(email!=NULL)
    {
        retorno=0;
    }
    return retorno;
}

void user_print(User*this)
{
    printf("\nuserId[%d] - Name: %s - Email: %s ",this->userId,this->name,this->email);
}
