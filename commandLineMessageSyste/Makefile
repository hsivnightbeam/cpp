name=king_test

options = -g -Wall -Wextra -pedantic -std=c++14

include_path=-IModel/MessageStore/ -IModel/UserStore/ -IController/ -IInterface/
sources=$(wildcard Model/MessageStore/*.cpp Model/UserStore/*.cpp Controller/*.cpp Interface/*.cpp  main.cpp)

default: $(name)

$(name): $(sources)
	rm -rf bin && mkdir bin && g++ $(options) $(include_path) -o bin/$@ $^
