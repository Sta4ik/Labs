#include <iostream>

void AllocatedMemory(int64_t**&, int64_t, int64_t);
void DeleteMemory(int64_t**&, int64_t);
int64_t SumRowsWithoutZero(int64_t**, int64_t, int64_t);
bool CheckZero(int64_t*, int64_t);
void SwapCols(int64_t**&, int64_t, int64_t);
int64_t EnterCols();
int64_t EnterRows();
void MakeElementZero(int64_t**&, int64_t, int64_t);
int32_t InputInputType();
void FillMatrix(int64_t**&, int64_t, int64_t);
void FillMatrixRandom(int64_t**&, int64_t, int64_t);
void PrintMatrix(int64_t**, int64_t, int64_t);
void FindFirstRowWithZero(int64_t**, int64_t, int64_t);
void FindSaddlePoints(int64_t**, int64_t, int64_t);