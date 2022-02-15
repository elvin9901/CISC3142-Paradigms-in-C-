// This file shows basic functions of reading in a CSV file using C++98
// Please add your name to your code!

/* Homework Objective: fix this program to match the requirements listed:
  1. successfully reads all lines of the input file
  2. calculate the average price per brand, average price per category
  3. writes to an output file
  4. for each unique year, list the count of skus and also print out the skus as a list i.e. 2000 (3): 111, 211, 311 and make a new line per year.

All programs must be able to compile in C++98 standard (the default version on Linux Machine). That means you cannot use the new features of C++11! :(

*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

int main() {

    // define variables
    string sku, brand, category, year, price;
    vector<int> vSKU;
    vector<string> vBrand;
    vector<string> vCategory;
    vector<int> vYear;
    vector<float> vPrice;

    // variables for Feature 1: calculate the average price per brand, average price per category.
    map<string, float> mTotalBrandPrice; // Used to sum all the prices of SKU of the same brand.
    map<string, int> mBrandCount; // Used to count all the prices of SKU of the same brand.
    map<string, float> mTotalCategoryPrice; //Used to sum all the prices of SKU of the same brand.
    map<string, int> mCategoryCount; // Used to count all the prices of SKU of the same brand.
    //
    map<int, vector<int> > mYearSKUs;
    map<int, int> mYearSKUsCount; // Used to count all the prices of SKU of the same brand.

    // input and output file
    ifstream in_stream;
    in_stream.open("./data.csv"); //opening the file.
    ofstream out_steream;
    out_steream.open ("output.txt"); // opening the output file.

    if (!in_stream.fail()) { //if the file is open

        string line;
        getline(in_stream, line); // The first line!: The column names : not needed!
        while (getline(in_stream, sku,
                       ',')) { //while the end of file is NOT reached : Only selecting the sku field (1st column). The rest of  the fields are parsed in the loop.
            // Fields: sku,brand,category,year,price

            stringstream ssku(sku);
            int iSKU = 0;
            ssku >> iSKU;
            vSKU.push_back(iSKU);

            getline(in_stream, brand, ',');
            vBrand.push_back(brand);
            mBrandCount[brand] += 1;// counting the occurrences of each brand


            getline(in_stream, category, ',');
            vCategory.push_back(category);
            mCategoryCount[category] += 1;// counting the occurrences of each category

            getline(in_stream, year, ',');
            stringstream syear(year);
            int iYear;
            syear >> iYear;
            vYear.push_back(iYear); // counting the occurrences of each year
            if (mYearSKUs.find(iYear) !=
                mYearSKUs.end()) { // if the year exists in the map => not the first occurence on the file
                mYearSKUs[iYear].push_back(iSKU); // add the SKU to the list of SKUs for this year
            } else {
                vector<int> vYearSKUs; // new vector that will contain the SKUs for the year
                vYearSKUs.push_back(iSKU);// add the SKU to the list of SKUs for the new year
                mYearSKUs[iYear] = vYearSKUs; // add the year and the first SKU to the list
            }
            mYearSKUsCount[iYear] += 1;
            getline(in_stream, price, '\n');
            stringstream sprice(price);
            float fPrice;
            sprice >> fPrice;
            vPrice.push_back(fPrice);
            mTotalCategoryPrice[category] += fPrice; // sum of the price of the SKUs of each category
            mTotalBrandPrice[brand] += fPrice; // sum of the price of the SKUs of each brand

        }

        in_stream.close(); //closing the file

    } else {
        cout << "Unable to open file";
    }



    /* Iterating over the categories and printing the average price for each
     * Average price = sum of price / count of occurrences of the category */
    for (std::map<string, float>::iterator it = mTotalCategoryPrice.begin(); it != mTotalCategoryPrice.end(); ++it)
        out_steream << "Category " << it->first << " Average Price is " << it->second / mCategoryCount[it->first] << '\n';
    out_steream << "------------------------------------------------  " << endl;

    /* Iterating over the brands and printing the average price for each
     * Average price = sum of price / count of brands of the category */
    for (std::map<string, float>::iterator it = mTotalBrandPrice.begin(); it != mTotalBrandPrice.end(); ++it)
        out_steream << "Brand " << it->first << " Average Price is " << it->second / mBrandCount[it->first] << '\n';
    out_steream << endl;
    out_steream << "-------------------------------------------------  " << endl;

    /* Feature 2: for each unique year, list the count of SKUs and print out the SKUs as a list
     * Iterating over the years and printing :
     *  * the year and the count SKUs
     *  * the list of SKUs */
    for (std::map<int, int>::iterator it = mYearSKUsCount.begin(); it != mYearSKUsCount.end(); ++it){
        out_steream << it->first << " ( " << it->second << " ) : ";
        for (int j = 0; j < mYearSKUs[it->first].size()-1; j++) { // iterate over the elements of the SKUs of the year
            out_steream << mYearSKUs[it->first][j] << ", ";// display the SKU
        }
        out_steream << mYearSKUs[it->first][mYearSKUs[it->first].size()-1]; //display the last SKU of the year
        out_steream << endl; // add a line break
    }
    out_steream << endl;
    out_steream << "--------------------------------------------------  " << endl;

    //output values
    out_steream << "SKU" << "\t" << "Brand" << "\t" << "Category" << "\t" << "Year" << "\t" << "Price" <<  endl;

    for (int j = 0; j < vSKU.size(); j++) {
        out_steream << vSKU[j] << "\t" << vBrand[j] << "\t \t" << vCategory[j] << "\t \t \t" << vYear[j] << "\t" << vPrice[j] << endl;
    }
}
