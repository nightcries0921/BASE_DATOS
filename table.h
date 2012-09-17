#ifndef TABLE_H
#define TABLE_H
#include <table_pointers.h>
#include <table_fields.h>
#include <bitsmap.h>
#include <metadatatable.h>
#include <QDataStream>
#include <header.h>

class Table
{
public:
    Table(int num,MetaDataTable &meta,Table_Fields cam);
    void setBitsMap(QBitArray *bits);
    void setFile(QFile *file);
    void setHeader(Header &head);
    int addRegister(QList<QString>Regis);
    int canAddRegister();
    QByteArray joinToMe(QList<QString>list);
    int num_table;
    QList<QByteArray> StackRegisters;
    int addAllRegistersToFile();
private:
    Table_Fields listFields;
    MetaDataTable metaData;
    int registerCant;
    BitsMap bitsmap;
    QFile *fileOpened;
    Header header;
    int getBytesPositionToWriteRegister(int val);
    void fullBlockWithRegister(int blockNum);
    void creatListPointers(int blockNum);
    int addRegisterToFile(QByteArray info);
};

#endif // TABLE_H
