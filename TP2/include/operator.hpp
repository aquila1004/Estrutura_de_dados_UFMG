#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include <string.h>
#include "graph.hpp"
#include "sort.hpp"

int isValidOperation(const char* operation);
void handleOperation(const char* operation, Grafo* grafo, CoresVertices* cores, int result);

#endif