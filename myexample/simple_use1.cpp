#include <cassert>
#include <iostream>
#include "leveldb/db.h"

int main() {
    leveldb::DB* db;

    {
        leveldb::Options options;
        options.create_if_missing = true;
        options.compression = leveldb::kNoCompression;
        leveldb::Status status = leveldb::DB::Open(options, "testdb", &db);
        assert(status.ok());
    }

    {
        leveldb::WriteOptions options;
        leveldb::Status status = db->Put(options, "[Key]", "[Value]");
        assert(status.ok());
    }

    {
        std::string key = "[Key]";
        std::string value;
        leveldb::ReadOptions read_options;
        leveldb::Status status = db->Get(read_options, key, &value);
        assert(status.ok());
        std::cout << "Key: " << key << ", Value: " << value << std::endl;
    }

    delete db;
}
