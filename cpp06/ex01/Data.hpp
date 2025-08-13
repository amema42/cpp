#ifndef DATA_HPP
#define DATA_HPP

struct Data {
private:
    int _intNumber;
    float _floatNumber;
    char _c;

    
public:
    Data();
    Data(int intNumber, float floatNumber, char c);
    ~Data();
    int getIntNumber() const;
    float getFloatNumber() const;
    char getChar() const;
};

#endif