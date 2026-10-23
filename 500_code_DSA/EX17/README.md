# Find Majority Element (Boyer–Moore Majority Vote Algorithm)

## 1. Đề bài (Problem Statement)
Given an integer array containing duplicates, return the majority element if present. A majority element appears more than `n/2` times, where `n` is the size of the array.

## 2. Thuânt toán (Algorithm:  **Boyer–Moore Majority Vote Algorithm**)

* **Bước 1: Tìm ứng viên tiềm năng (`candidate`)** - Ứng viên tìm được có thể không thỏa mãn yêu cầu đề bài.
  * Khởi tạo `candidate = arr[0]` và biến đếm `count = 0`.
  * Duyệt qua từng phần tử từ `i = 0` đến `n - 1`: nếu `arr[i] == candidate` thì tăng `count` lên 1, ngược lại giảm `count` đi 1 
  * Ngay khi `count == 0`, ta đổi ứng viên mới là phần tử kế tiếp `candidate = arr[i + 1]` (nếu `i < n - 1`). Ở bước lặp tiếp theo, ứng viên mới này sẽ tự khớp với chính nó và đưa `count` tăng lại lên `1`.
* **Bước 2: Kiểm tra lại ứng viên (`check_cnt`)**
  * Duyệt lại mảng một lần nữa để đếm số lần xuất hiện thực tế của `candidate`.
  * Nếu số lần xuất hiện lớn hơn `n / 2`, kết luận đó là phần tử đa số, ngược lại in ra `"Non_existent"`.


## 3. Code
### Cách hoạt động của hàm `majority_vote`:
1. **Vòng lặp `for` thứ nhất:** Khởi tạo `candidate = arr[0]`, `count = 0`. Duyệt từ `i = 0` đến `n - 1`: tăng `count` khi gặp phần tử bằng `candidate`, giảm `count` khi gặp phần tử khác. Nếu `count` về `0` (các phần tử trước đó đã triệt tiêu hết cho nhau), gán `candidate = arr[i + 1]` để chọn phần tử tiếp theo làm ứng viên mới.
2. **Vòng lặp `for` thứ hai:** Duyệt toàn bộ mảng qua con trỏ `*(arr + i)` để đếm số lần `candidate` xuất hiện vào `check_cnt`. Nếu `check_cnt > n / 2` thì bật cờ `check = 1`.
3. **In kết quả:** Nếu `check == 1` thì in ra `candidate`, ngược lại in `"Non_existent"`.

## 4. Test Cases & Output

### Test Case 1: 
**Input:**
```text
11
2 8 7 2 2 5 2 3 1 2 2
```
**Output:**
```text
2
```

### Test Case 2: 
**Input:**
```text
6
1 2 3 1 2 1
```
**Output:**
```text
Non_existent
```

### Test Case 3: 
**Input:**
```text
7
3 1 3 4 3 2 3
```
**Output:**
```text
3
```