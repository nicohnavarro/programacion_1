#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

typedef struct{
    int userId;
    char name[33];
    char email[65];
}User;


User* user_new();
User* user_newParametros(int userId,char* name, char* email);
void user_delete(User* this);
int user_setUserId(User*this,int userId);
int user_getUserId(User*this,int* userId);
int user_setName(User*this,char* name);
int user_getName(User*this,char* name);
int user_setEmail(User*this,char* email);
int user_getEmail(User*this,char* email);
void user_print(User*this);

#endif // USER_H_INCLUDED
