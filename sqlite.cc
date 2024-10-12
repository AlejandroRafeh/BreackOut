
static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   //printf("%s: ", (const char*)data);
   
   for(i = 0; i<argc; i++){
      switch(argc){
         
         case 0:
              printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
         break;

         case 1:
                printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
         break;

         case 2:
                 printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
         break;

         case 3:
                   printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
         break;

      }
    
   }
   
   printf("\n");
   return 0;
}



void HandleSqlite(){
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;
   const char* data = "Callback function called";

   /* Open database */
   rc = sqlite3_open("breack_out.db", &db);
   
   if( rc ) {
      printf("Can't open database: %s\n", sqlite3_errmsg(db));
   } else {
      printf("Opened database successfully\n");
   }

   /* Create SQL statement */
   sql = "SELECT * from Levels";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
   
   if( rc != SQLITE_OK ) {
      printf( "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      printf( "Operation done successfully\n");
   }
   sqlite3_close(db);
}