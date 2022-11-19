#include <iostream>
#include <stdint.h>
#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

int main()
{
	Data data;
	std::cout << "Pointer before serialization: " << &data << std::endl;
	uintptr_t serial = serialize(&data);
	std::cout << "Serialized value: " << std::hex << serial << std::endl;
	Data* unserializedData = deserialize(serial);	
	std::cout << "Deserialized pointer: " << unserializedData << std::endl;
}