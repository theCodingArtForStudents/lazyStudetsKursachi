#include "field.h"


//FieldType::FieldType()
//{
//    _data = new anyType();
//}

bool operator <(const anyType &left, const anyType &right)
{
    return left._iData         <   right._iData
            || left._cData     <   right._cData
            || left._countData <   right._countData
            || left._dData     <   right._dData;

}

bool operator >(const anyType &left, const anyType &right)
{
    return left._iData         >   right._iData
            || left._cData     >   right._cData
            || left._countData >   right._countData
            || left._dData     >   right._dData;

}

anyType &anyType::operator =(const anyType &obj)
{
    _cData = obj._cData;
    _iData = obj._iData;
    _dData = obj._dData;
    _countData = obj._countData;
    return *this;
}

anyType &anyType::operator =(const int &value)
{
  _iData = value;
  return *this;
}

anyType &anyType::operator =(const std::string &value)
{
  *_cData = value;
  return *this;
}

anyType &anyType::operator =(const double &value)
{
  _dData = value;
  return *this;
}

anyType &anyType::operator =(const size_t &value)
{
  _countData = value;
  return *this;
}


anyType *FieldType::data() const
{
    return _data;
}

anyType *FieldType::data()
{
    return _data;
}

FieldType::FieldType()
{
  _data = new anyType();
  _type = UNDEFINEDTYPE;
}

FieldType::FieldType(const int &other)
{
    _type = fieldType::INTEGER;
    _data = new anyType(other);
}

FieldType::FieldType(const std::string &other)
{
    _type = STRING;
    _data = new anyType(other);
}

FieldType::FieldType(const size_t &other)
{
    _type = COUNTER;
    _data = new anyType(other);
}

FieldType::FieldType(const double &other)
{
    _type = DOUBLE;
    _data = new anyType(other);
}

FieldType &FieldType::operator =(const FieldType &obj)
{
  this->_data = obj.data();
  return *this;
}

FieldType &FieldType::operator =(const int &value)
{
  *this->_data = value;
  return *this;
}

FieldType &FieldType::operator =(const std::string &value)
{
  *this->_data = value;
  return *this;
}

FieldType &FieldType::operator =(const double &value)
{
  *this->_data = value;
  return *this;
}

FieldType &FieldType::operator =(const size_t &value)
{
  *this->_data = value;
  return *this;
}

bool operator >(const FieldType &left, const FieldType &right)
{
  return left.data() > right.data();
}

bool operator <(const FieldType &left, const FieldType &right)
{
  return left.data() < right.data();
}

bool operator ==(const FieldType &left, const int &right)
{
    return left.data()->_iData == right;
}

bool operator ==(const FieldType &left, const FieldType &right)
{
    return left.data() == right.data();
}

std::string &FieldType::toString()
{
    return *(new std::string(*_data->_cData));
}

FieldType::~FieldType()
{
    delete _data;
}

fieldType FieldType::type() const
{
    return _type;
}

std::ostream &operator <<(std::ostream &out, const FieldType &obj)
{
    switch ((obj.type())) {
        case INTEGER:
            out << (obj.data()->_iData);
            break;
        case STRING:
            out << (obj.data()->_cData);
            break;
        case DOUBLE:
            out << (obj.data()->_dData);
            break;
        case COUNTER:
            out << (obj.data()->_countData);
            break;
        default:
            out << "NAN";
            break;
        }
    return out;
}

std::istream &operator >>(std::istream &in, const FieldType &obj)
{
    switch (int(obj.type())) {
        case INTEGER:
            in >> (obj.data()->_iData);
            break;
        case STRING:
            in >> *(obj.data()->_cData);
            break;
        case DOUBLE:
            in >> (obj.data()->_dData);
            break;
        case COUNTER:
            in >> (obj.data()->_countData);

            break;
        }
    in >> obj.data()->_iData;
    return in;
}
