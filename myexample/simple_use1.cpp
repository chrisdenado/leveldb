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
        leveldb::ReadOptions read_options;
        db->Put(options, "k1", "v1");
        db->Put(options, "k1", "v2");
        db->Put(options, "k2", "v1");
        db->Delete(options, "k1");
        db->Put(options, "k2", "v2");
        auto iter = db->NewIterator(read_options);
        iter->SeekToFirst();
        while(iter->Valid())
        {
            std::string str = iter->key().data() + std::string(iter->value().data());
            std::cout << iter->key().data() << iter->value().data() << std::endl;
            iter->Next();
        }

        iter->SeekToLast();
        while(iter->Valid())
        {
            std::string str = iter->key().data() + std::string(iter->value().data());
            std::cout << iter->key().data() << iter->value().data() << std::endl;
            iter->Prev();
        }
    }

    {
        std::string key = "k2";
        std::string value;
        leveldb::ReadOptions read_options;
        leveldb::Status status = db->Get(read_options, key, &value);
        assert(status.ok());
        std::cout << "Key: " << key << ", Value: " << value << std::endl;
    }

//    delete db;
}
