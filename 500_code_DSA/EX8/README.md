# Find Maximum Length Subarray Having Equal Number of 0’s and 1’s

## 1. Đề bài (Problem Statement)
Given a binary array containing 0’s and 1’s, find the largest subarray with equal numbers of 0’s and 1’s.

## 2. Thuật toán (Algorithm) Idea
* **Quy đổi bài toán:** Ta coi các phần tử `0` trong mảng ban đầu bằng `-1`. Khi đó, một mảng con có số lượng số `0` bằng số lượng số `1` sẽ tương đương với việc mảng con đó có **tổng các phần tử bằng `0`**.
* **Sử dụng mảng cộng dồn `arr_B[]`:**
  * Khởi tạo `arr_B[0] = 0`.
  * Tại mỗi vị trí `i`: nếu `arr[i] == 0` thì `arr_B[i + 1] = arr_B[i] - 1`, ngược lại nếu `arr[i] == 1` thì `arr_B[i + 1] = arr_B[i] + 1`.
* **Tìm mảng con lớn nhất:** 
  * Nếu tại hai vị trí `i` và `j` (`j > i`) có `arr_B[i] == arr_B[j]`, nghĩa là tổng các phần tử từ chỉ số `i` đến `j - 1` của mảng gốc bằng `0` (số lượng `0` và `1` bằng nhau).
  * Độ dài của mảng con này là `j - i`. Ta lưu lại thông tin các mảng con thỏa mãn vào mảng cấu trúc `subarr` và cập nhật độ dài lớn nhất `max`.

## 3. Code 

### Cách hoạt động của hàm `find_largest_subarr`:
1. **Khởi tạo:** Dùng biến `max = 0` để theo dõi độ dài lớn nhất và mảng cấu trúc `A[]` (kiểu `subarr`) để lưu độ dài (`max_element`), vị trí bắt đầu (`start`) và vị trí kết thúc (`end`) của các mảng con thỏa mãn.
2. **Duyệt các cặp chỉ số `(i, j)`:** Sử dụng 2 vòng lặp lồng nhau (`0 <= i < j <= num_arr`):
   * Kiểm tra điều kiện `arr_B[i] == arr_B[j]`. Nếu bằng nhau, đoạn từ `i` đến `j - 1` có số lượng `0` và `1` bằng nhau.
   * Lưu độ dài `j - i`, chỉ số đầu `i`, chỉ số cuối `j - 1` vào `A[num]`, đồng thời cập nhật `max = find_max(max, j - i)` và tăng biến đếm `num`.
3. **In kết quả:**
   * Nếu `max == 0` (không có cặp nào thỏa mãn), in ra thông báo `"There is no satisfied subarr"`.
   * Nếu `max > 0`, duyệt lại danh sách `A[]` và in ra toàn bộ các mảng con có độ dài đạt giá trị lớn nhất (`A[j].max_element == max`).

## 4. Test Cases & Output

### Test Case 1
**Input:**
```text
7
0 0 1 0 1 0 0
```
**Output:**
```text
0 1 0 1 
```

### Test Case 2:
**Input:**
```text
6
0 0 1 0 1 1
```
**Output:**
```text
0 1 0 1 
0 0 1 1 
```

### Test Case 3
**Input:**
```text
4
1 1 1 1
```
**Output:**
```text
There is no satisfied subarr
```