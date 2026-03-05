#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct PackedData {
    int frequencies[18];
    int length;
    int minValue;
    int maxValue;
};

PackedData packArray(const vector<int>& arr) {
    PackedData data;
    data.length = arr.size();
    for (int i = 0; i < 18; i++)
    {
        data.frequencies[i] = 0;
    }


    if (arr.empty()) {
        data.minValue = data.maxValue = 0;
        return data;
    }

    data.minValue = arr[0];
    data.maxValue = arr[arr.size() - 1];

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= 0 && arr[i] <= 17) {
            data.frequencies[arr[i]]++;
        }
    }
    return data;
}

vector<int> unpackArray(const PackedData& data) {
    vector<int> result;
    result.reserve(data.length);

    for (int value = data.minValue; value <= data.maxValue; value++)
    {
        if (value >= 0 && value <= 17) {
            for (int j = 0; j < data.frequencies[value]; j++)
            {
                result.push_back(value);
            }
        }
    }
    return result;
}

void printArray (const vector<int>& arr, int maxPrint = 50) {
    if (arr.empty()) {
        cout << "Zero " << endl;
        return;
    }

    //cout << min(maxPrint, (int)arr.size()) << endl;
    for (int i = 0; i < min(maxPrint, (int)arr.size()); i++)
    {
        cout << arr[i] << " ";
    }
    if (arr.size() > maxPrint) {
        cout << "...";
    }
    cout << endl;

    cout << "Size: " << arr.size() << endl;
}

int main() {
    const int N = 1000;
    vector<int> testArray;
   
    for (int i = 0; i < N; i++) {
        int val;
        if (i < 200) val = i / 20;
        else if (i < 400) val = 10;
        else if (i < 550) val = 11;
        else if (i < 670) val = 12;
        else if (i < 770) val = 13;
        else if (i < 850) val = 14;
        else if (i < 910) val = 15;
        else if (i < 960) val = 16;
        else val = 17;

        testArray.push_back(val);
    }
   
    cout << "The original array: " << endl;
    printArray(testArray);
    cout << "Range of values: [" << testArray[0] << ", " << testArray[testArray.size() - 1] << "]" << endl;

    PackedData packed = packArray(testArray);
    cout << "Frequencies of values:" << endl;
    for (int i = 0; i <= 17; i++) {
        if (packed.frequencies[i] > 0) {
            cout << "  value " << i << ": " << packed.frequencies[i] << endl;
        }
    }

    vector<int> restored = unpackArray(packed);
    cout << "The restored array:" << endl;
    printArray(restored);
    return 0;
}
