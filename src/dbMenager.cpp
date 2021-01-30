#include "include/dbMenager.h"
#include <vector>
#include "libs/sqlite3/sqlite3.h"

void DbMenager::initTable(){
 string querryTmp;
 const char* query;



 querryTmp = "CREATE TABLE IF NOT EXISTS cars (\n"
          "vin VARCAHR(17) PRIMARY KEY,\n"
          "mark VARCAHR(20),\n"
          "model VARCAHR(20),\n"
          "year INTEGER,\n"
          "mileage INTEGER,\n"
          "enginePower INTEGER,\n"
          "colour VARCAHR(20)\n"
          ")";
 query = querryTmp.c_str();

    sqlite3_stmt *stmt;
    sqlite3_prepare(this->db,query,querryTmp.size(),&stmt,NULL);
    if (sqlite3_step(stmt) != SQLITE_DONE) cout << "error" << endl;



}

DbMenager::~DbMenager(){
    sqlite3_close(this->db);
}



DbMenager::DbMenager(){


    int rc = sqlite3_open("car.db",&this->db);
    if(rc != SQLITE_OK){
        cout<<"error"<<endl;
    }

    initTable();
}
DbMenager::DbMenager(sqlite3 *db){
    this->db = db;
    initTable();
}

int loadCarData(void *ptr, int argc, char* argv[], char* cols[]){
    vector<string> v;

    for(int i=0;i<argc;i++){
        v.push_back(argv[i] ? argv[i] : "(NULL)");
    }
    return 0;
}

bool DbMenager::isInDB(string vin){
    string queryTmp;
    const char* query;
    vector<string> carData;
    sqlite3_stmt *stmt;
    queryTmp = "SELECT * FROM cars WHERE vin='" + vin + "';";
    query=queryTmp.c_str();

    sqlite3_prepare(this->db,query,-1,&stmt,NULL);
    sqlite3_step(stmt);

    return sqlite3_data_count(stmt)!=0;

}

Car DbMenager::find(string vin){
    string queryTmp;
    const char* query;

    vector<string> carData;
    sqlite3_stmt *stmt;
    queryTmp = "SELECT * FROM cars WHERE vin='" + vin + "';";
    query=queryTmp.c_str();

    sqlite3_prepare(this->db,query,-1,&stmt,NULL);
    sqlite3_step(stmt);




    if(sqlite3_data_count(stmt)!=0) {
        for (int colIndex = 0; colIndex < sqlite3_column_count(stmt); colIndex++) {
            carData.push_back((char *) sqlite3_column_text(stmt, colIndex));

        }

        Car car = Car(carData[0],carData[1],carData[2],atoi(carData[3].c_str()),atoi(carData[4].c_str()),atoi(carData[5].c_str()),carData[6]);
        return car;
    }else{
        Car car = Car("NULL","NULL","NULL",0,0,0,"NULL");
        return car;
    }


}

void DbMenager::updateCarInDB(Car &car){
    string queryTmp;
    const char* query;
    queryTmp ="UPDATE cars\n"
              "SET "
              "mileage='"+to_string(car.getMileage())+"',"+
              "\nenginePower='"+to_string(car.getEnginePower())+"',"+
              "\ncolour='"+car.getColour()+"'"+
              "\nWHERE "
              "vin='"+car.getVin()+"'"+
              ";";
    query = queryTmp.c_str();

    sqlite3_stmt *updateStmt;
    sqlite3_prepare(this->db, query, -1, &updateStmt, NULL);
    if (sqlite3_step(updateStmt) != SQLITE_DONE) cout << "Didn't Update Item!" << endl;


}

bool DbMenager::addToDB(Car &car){
    string queryTmp;
    const char* query;

    queryTmp = "INSERT INTO cars (vin,mark,model,year,mileage,enginePower,colour) VALUES ('"+car.getVin()+"','"+car.getMark()+"','"+car.getModel()+"','"+to_string(car.getYear())+"','"+to_string(car.getMileage())+"','"+to_string(car.getEnginePower())+"','"+car.getColour()+"');";
    query=queryTmp.c_str();

    sqlite3_stmt *insertStmt;
    sqlite3_prepare(this->db, query, queryTmp.size(), &insertStmt, NULL);
    if (sqlite3_step(insertStmt) != SQLITE_DONE) {
        return false;
    }
    else {
        return true;
    }

}