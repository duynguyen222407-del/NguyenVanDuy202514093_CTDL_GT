# Find Equilibrium Index of an Array

## 1. Đề bài (Problem Statement)
Given an integer array, find all equilibrium indexes in it. An equilibrium index of an array is an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes.

## 2. Thuật toán (Algorithm Idea)
Để tìm các chỉ số cân bằng một cách hiệu quả mà không cần tính lại tổng liên tục cho từng phần tử, ta sử dụng kỹ thuật mảng tổng dồn:
* **Mảng tổng bên trái (`sum_left[]`):** Tạo một mảng `sum_left[]` với `sum_left[i]` lưu tổng các phần tử nằm bên trái của chỉ số `i` (tổng từ phần tử `0` đến `i - 1`). Khởi tạo `sum_left[0] = 0`.
* **Duyệt ngược từ cuối mảng (`sum_right`):** Sử dụng một biến `sum_right` để tính tổng các phần tử nằm bên phải của chỉ số hiện tại (khởi tạo bằng `0`). Duyệt ngược chỉ số `i` từ `n - 1` về `0`:
  * Nếu tại vị trí `i` mà `sum_right == sum_left[i]`, nghĩa là tổng các phần tử bên trái bằng tổng các phần tử bên phí phải $\rightarrow$ In ra chỉ số `i`.
  * Cộng dồn phần tử `arr[i]` vào `sum_right` để tiếp tục xét cho các phần tử phía trước.

## 3. Code & Giải thích thuật toán



### Cách hoạt động:
1. **Xây dựng mảng `sum_left`:** Vòng lặp đầu tiên tính tổng tích lũy từ trái sang phải, giúp ta biết tổng các phần tử đứng trước mỗi vị trí `i` là bao nhiêu.
2. **Kiểm tra cân bằng ngược từ phải qua trái:** Vòng lặp thứ hai duyệt mảng từ cuối về đầu. Biến `sum_right` có vai trò lưu tổng các phần tử bên phải. 
3. Nếu điều kiện `sum_right == sum_left[i]` thỏa mãn, chương trình in ra chỉ số `i` đó là một chỉ số cân bằng.
4. Ta có sử dụng thêm một biến `check` để kiểm tra xem có chỉ số thỏa mãn yêu cầu không. Khởi tạo ban đầu bằng 0, nếu điều kiện ở $3$ thỏa mãn thì cho `check = 1` 
5. Khi `check` vẫn giữ nguyên giá trị 0 như ban đầu thì in ra thông báo `Khong ton tai chi so thoa man`.
## 4. Test Cases & Output

### Test Case 1: 
**Input:**
```text
7
0 -3 5 -4 -2 3 1
```
**Output:**
```text
3 0 
```

### Test Case 2: 
**Input:**
```text
5
1 2 3 3 0
```
**Output:**
```text
2 
```

### Test Case 3: 
**Input:**
```text
3
1 2 3
```
**Output:**
```text
Khong ton tai chi so thoa man
```