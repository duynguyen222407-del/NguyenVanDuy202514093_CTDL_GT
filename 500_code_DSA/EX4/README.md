# Sort Binary Array in Linear Time

## 1. Đề bài (Problem Statement)
Given a binary array, sort it in linear time and constant space. The output should print all zeros, followed by all ones.

## 2. Thuật toán (Algorithm)
* **Bước 1: Đếm số lượng phần tử `0`**
  * Duyệt qua toàn bộ mảng và đếm tổng số lần xuất hiện của số `0`, lưu vào biến `cnt`.
* **Bước 2: Ghi đè lại vào mảng gốc**
  * Điền `cnt` phần tử đầu tiên của mảng (từ chỉ số `0` đến `cnt - 1`) bằng giá trị `0`.
  * Điền toàn bộ các phần tử còn lại của mảng (từ chỉ số `cnt` đến `n - 1`) bằng giá trị `1`.

## 3. Code 

### Cách hoạt động của hàm `sort_array`:
1. **Đếm số lượng số `0` (Vòng lặp thứ nhất):** Khởi tạo biến đếm `cnt = 0`. Duyệt chỉ số `index` từ `0` đến `n - 1`, mỗi khi gặp `arr[index] == 0` thì tăng `cnt` lên `1`.
2. **Ghi đè các số `0` vào đầu mảng (Vòng lặp thứ hai):** Duyệt biến `j` từ `0` đến `cnt - 1` và gán `arr[j] = 0`.
3. **Ghi đè các số `1` vào cuối mảng (Vòng lặp thứ ba):** Duyệt biến `k` từ vị trí `cnt` đến `n - 1` và gán toàn bộ các vị trí còn lại bằng `1` (`arr[k] = 1`).

## 4. Test Cases & Output

### Test Case 1:
**Input:**
```text
10
1 0 1 0 1 0 0 1 0 1
```
**Output:**
```text
0 0 0 0 0 1 1 1 1 1 
```

### Test Case 2: 
**Input:**
```text
6
1 1 1 0 0 0
```
**Output:**
```text
0 0 0 1 1 1 
```

### Test Case 3:
**Input:**
```text
4
1 1 1 1
```
**Output:**
```text
1 1 1 1 
```