#pragma once
#include <iostream>
#include<string>
#include<fstream>
#include "Struct illness.h"
#include "Struct Patient.h"
#include "list of diseases.h"
#include "List of patients.h"
#include <time.h>
#include <windows.h>



list_of_patients* load_data_base();

void finish(list_of_patients* List);
void run();
