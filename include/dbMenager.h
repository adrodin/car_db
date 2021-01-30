
#ifndef V3_DBMENAGER_H
#define V3_DBMENAGER_H

#include "libs/sqlite3/sqlite3.h"
#include "car.h"
class DbMenager{
private:
    sqlite3 *db;
    void initTable();

public:

    DbMenager();
    ~DbMenager();
    DbMenager(sqlite3 *db);
    bool isInDB(string vin);
    Car find(string vin);
    void updateCarInDB(Car &car);
    bool addToDB(Car &car);
};

#endif //V3_DBMENAGER_H
