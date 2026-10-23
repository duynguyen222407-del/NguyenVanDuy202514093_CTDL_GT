# Sort an Array of 0s, 1s, and 2s (Dutch National Flag Problem)

## 1. Đề bài (Problem Statement)
Given an array containing only 0’s, 1’s, and 2’s, sort it in linear time and using constant space.

## 2. Thuật toán(Algorithm)
Ta sử dụng 3 con trỏ (`low`, `mid`, `high`) để chia mảng thành 4 phần: 
* `[0 ... low - 1]`:** Chứa toàn bộ phần tử `0`.
* `[low ... mid - 1]`:** Chứa toàn bộ phần tử `1`.
* `[mid ... high]`:** Vùng các phần tử chưa được kiểm tra.
* `[high + 1 ... n - 1]`:** Chứa toàn bộ phần tử `2`.

Sử dùng vòng lặp lặp qua các phần tử của mảng với mục tiêu là di chuyển `mid` và `high` tiến lại gần nhau cho đến khi các phần tử chưa được kiểm tra dều được duyệt qua (`mid > high`).

## 3. Code 
### Cách hoạt động của hàm `sort_arr`:
1. **Khởi tạo:** Đặt `low = 0` và `mid = 0` ở đầu mảng, `high = num_element - 1` ở phần tử cuối cùng của mảng.
2. **Vòng lặp `while (mid <= high)`:** Lặp chừng nào vẫn còn phần tử chưa được xét:
   * **Trường hợp `arr[mid] == 0`:** Đổi chỗ `arr[mid]` với `arr[low]` để đưa số `0` về vùng đầu mảng, sau đó tăng cả `low` và `mid` lên `1` (`low += 1`, `mid += 1`).
   * **Trường hợp `arr[mid] == 1`:** Số `1` đã nằm đúng vùng ở giữa nên giữ nguyên vị trí, chỉ cần tăng `mid` lên `1` (`mid += 1`) để xét phần tử kế tiếp.
   * **Trường hợp `arr[mid] == 2` (`else`):** Đổi chỗ `arr[mid]` với `arr[high]` để đẩy số `2` về vùng cuối mảng, sau đó giảm `high` đi `1` (`high -= 1`). Giữ nguyên `mid` để kiểm tra giá trị mới vừa được đổi từ vị trí `high` về ở vòng lặp tiếp theo.

## 4. Test Case & Output
### Test Case 1: 
**Input:**
```text
9
0 1 2 2 1 0 0 2 1
```
**Output:**
```text
0 0 0 1 1 1 2 2 2 
```

### Test Case 2: 
**Input:**
```text
6
2 2 1 1 0 0
```
**Output:**
```text
0 0 1 1 2 2 
```

### Test Case 3: 
**Input:**
```text
5
2 0 2 0 2
```
**Output:**
```text
0 0 2 2 2 
```