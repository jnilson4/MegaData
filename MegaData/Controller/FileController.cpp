//
//  FileController.cpp
//  MegaData
//
//  Created by Nilson, Jake on 3/29/17.
//  Copyright © 2017 Nilson. All rights reserved.
//

#include <stdio.h>

#include "FileController.hpp"

DoubleList<FoodItem> FileController :: readFoodItemDataFromFlieAsList(string filename)
{
    DoubleList<FoodItem> dataSource;
    string currentCSVLine;
    int rowCount = 0;
    
    ifstream dataFile(filename);
    
    if(dataFile.is_open())
    {
        while(!dataFile.eof())
        {
            getline(dataFile, currentCSVLine, '\r');
            stringstream parseCSV(currentCSVLine);
            
            string title, tempCost, tempCalorie, tempTasty;
            //Matching data types for structure.
            double cost;
            int calories;
            bool isDelish;
            
            //Each part as a string in order of the CSV - then convert after using stod, stoi.
            getline(parseCSV, title, ',');
            getline(parseCSV, tempCost, ',');
            getline(parseCSV, tempCalorie, ',');
            getline(parseCSV, tempTasty, ',');
            
            //Exclude first row headers
            if(rowCount != 0)
            {
                cost = stod(tempCost);
                calories = stoi(tempCalorie);
                isDelish = stoi(tempTasty);
                
                FoodItem temp(title);
                temp.setCost(cost);
                temp.setCalories(calories);
                temp.setDelicious(isDelish);
                
                dataSource.add(temp);
            }
            rowCount++;
            //Remove this line!!!
            cout << currentCSVLine << endl;
        }
        dataFile.close();
    }
    else
    {
        cerr << "NO FILE" << endl;
    }
    
    return dataSource;
}

void FileController :: WriteFoodItemDataStatistics(DoubleList<FoodItem> dataSource, string filename)
{
    ofstream saveFile(filename);
    
    if(saveFile.is_open())
    {
        saveFile << "these are teh contents of the list" << endl;
        for(int index = 0; index < dataSource.getSize(); index++)
        {
            saveFile << "Food Title: " << dataSource.getFromIndex(index).getFoodName() << endl;
        }
    }
    else
    {
        cerr << "File unavailable" << endl;
    }
    saveFile.close();
    
}
