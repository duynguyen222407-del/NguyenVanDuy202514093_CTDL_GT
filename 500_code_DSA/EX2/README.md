# Check if a Subarray with 0 Sum Exists or Not

## 1. Đề bài (Problem Statement)
Given an integer array, check if there is a sub-array (contiguous subset) with a sum equal to 0.

## 2. Thuật toán (Algorithm)
Bài toán này sử dụng kỹ thuật **Mảng cộng dồn** kết hợp với **Sắp xếp**:
* **Mảng cộng dồn (`tmp_sum`):** Tính tổng dồn các phần tử từ đầu mảng đến phần tử hiện tại. 
  * Nếu trong quá trình tính, có một tổng dồn `tmp_sum == 0`, điều đó có nghĩa là mảng con bắt đầu từ đầu đến vị trí hiện tại có tổng bằng `0` $\rightarrow$ Trả về `1` (True).

  * Nếu hai giá trị tổng dồn tại hai thời điểm khác nhau bằng nhau (`arr[i].sum == arr[i + 1].sum`), nghĩa là tổng các phần tử nằm giữa hai vị trí đó bằng `0`.

  * Ta lưu lại các giá trị tổng dồn kèm theo chỉ số vào một mảng cấu trúc `list_sum`, sau đó dùng thuật toán **Bubble Sort** để sắp xếp lại theo giá trị tổng tăng dần.

  * Duyệt mảng sau khi sắp xếp, nếu phát hiện hai phần tử liên tiếp có tổng `sum` bằng nhau, khi đó tồn tại một mảng con có tổng bằng `0` $\rightarrow$ Trả về `1`, ngược lại trả về `0`.

## 3. Code & Giải thích thuật toán


### Cách hoạt động:
1. **Hàm `check_subset`:** 
   * Duyệt qua từng phần tử, cộng dồn vào `tmp_sum`. Nếu ngay tại bước nào `tmp_sum == 0`, kết luận tồn tại và trả về `1`.
   * Nếu không, lưu giá trị `tmp_sum` và chỉ số `index` tương ứng vào mảng cấu trúc `arr[]`.
2. **Hàm `buble_sort_Str_arr`:** Sắp xếp mảng cấu trúc `arr[]` theo thứ tự tăng dần của trường `sum` bằng thuật toán Bubble Sort.

3. **Kiểm tra trùng lặp:** Duyệt mảng cấu trúc đã sắp xếp, nếu thấy hai phần tử liền kề có `sum` bằng nhau thì trả về `1`, nếu duyệt hết mà không có thì trả về `0`.

## 4. Test Cases & Output

### Test Case 1: 
**Input:**
```text
5
3 4 -7 3 1
```
**Output:**
```text
1
```

### Test Case 2: 
**Input:**
```text
4
1 -1 2 3
```
**Output:**
```text
1
```

### Test Case 3: 
**Input:**
```text
4
1 2 3 4
```
**Output:**
```text
0
```