#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysql.h"
#define IEM_dbhost "localhost"
#define IEM_dbuser "root"
#define IEM_dbpass "xnalet"
#define IEM_dbname "qwt"
#define IEM_dbtable "account"
#define IEM_db_name_col "uid"
#define IEM_db_pass_col "pwd"
#define IEM_io_buffer 256
int main(){
    char Inbuf[IEM_io_buffer],Sqlbuf[IEM_io_buffer];
    char n[IEM_io_buffer],*p;
    int i=0;
    MYSQL *mysql;
    MYSQL_RES *res;
    if(setvbuf(stdout,NULL,_IOLBF,0)!=0){
        return 0;
        exit(0);
    }
    while(1){
        if (fgets(Inbuf, IEM_io_buffer, stdin) == NULL)
            printf("ERR\n");
            if ((p = strchr(Inbuf,'\n')) != NULL)
                *p = '\0';          /* strip /n */
            if ((p = strchr(Inbuf, ' ')) == NULL) {
                printf("ERR\n");
                continue;
            }
            *p++ = '\0';
            break;
    }
                            /* varlidate the user via mysql database */
                            sprintf(Sqlbuf,"select "IEM_db_name_col" from "IEM_dbtable" where "IEM_db_name_col"='%s' and "IEM_db_pass_col"='%s' and expiredate>=current_date",Inbuf,p );
                                mysql=mysql_init(NULL);
                                if(mysql==NULL){
                                            printf("ERR\n");

                                }
                                if(mysql_real_connect(mysql,IEM_dbhost,IEM_dbuser,IEM_dbpass,IEM_dbname,0,NULL,0)==NULL){
                                            printf("ERR\n");

                                }
                                if(mysql_query(mysql,Sqlbuf)!=0){
                                            printf("ERR\n");

                                }
                                if(!(res=mysql_store_result(mysql))){
                                            printf("ERR\n");
                                                    mysql_close(mysql);

                                }
                                    if(res->row_count==1)
                                                printf("OK\n");
                                        else
                                                    printf("ERR\n");
                                            mysql_free_result(res);
                                                mysql_close(mysql);
                                                    return 1;

}

