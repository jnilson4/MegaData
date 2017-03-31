//
//  FileController.h
//  MegaData
//
//  Created by Nilson, Jake on 3/29/17.
//  Copyright © 2017 Nilson. All rights reserved.
//

#ifndef FileController_hpp
#define FileController_hpp

#include "../Model/DoubleList.hpp"
#include "../Model/FoodItem.hpp"
#include "../Model/CrimeData.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class FileController
{
private:
    DoubleList<FoodItem> foodItemList;
public:
    DoubleList<FoodItem> readFoodItemDataFromFlieAsList(string filename);
    void WriteFoodItemDataStatistics(DoubleList<FoodItem> source, string filename);
};

#endif /* FileController_h */
