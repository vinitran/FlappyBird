#include "List_coordinates.h"

List_coordinates::List_coordinates(const char* file_name)
{
    list.open(file_name);
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            list >> arr_position[i][j];
        }
    }
}
List_coordinates::~List_coordinates()
{}
