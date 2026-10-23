# Move All Zeros Present in an Array to the End

## 1. Đề bài (Problem Statement)
Given an integer array, move all zeros present in it to the end. The solution should maintain the relative order of items in the array and should not use constant space.

## 2. Thuật toán (Algorithm: **Two-Pointer**)
Để dồn toàn bộ các số `0` về cuối mảng mà vẫn giữ nguyên thứ tự tương đối của các phần tử khác `0` ngay trên mảng gốc (in-place):
* **Bước 1: Dồn các phần tử khác `0` lên đầu mảng**
  * Sử dụng một con trỏ `index` (khởi tạo bằng `0`) để đánh dấu vị trí tiếp theo cần điền phần tử khác `0`.
  * Duyệt biến `j` từ đầu đến cuối mảng: mỗi khi gặp phần tử `arr[j] != 0`, ta gán nó vào vị trí `arr[index]` và tăng `index` lên `1`.
* **Bước 2: Điền các số `0` vào phần còn lại ở cuối mảng**
  * Sau khi vòng lặp đầu kết thúc, toàn bộ các phần tử khác `0` đã ở đoạn `[0 ... index - 1]`.
  * Duyệt tiếp từ vị trí `index` đến `num_element - 1` và gán tất cả các phần tử này bằng `0`.


## 3. Code 

### Cách hoạt động của hàm `move_zero`:
1. **Khởi tạo:** Đặt biến `index = 0` làm mốc lưu vị trí cho các số khác `0`.
2. **Vòng lặp `for` thứ nhất:** Quét qua từng phần tử `arr[j]` từ `0` đến `num_element - 1`. Nếu `arr[j]` khác `0`, ghi đè giá trị đó vào `arr[index]` rồi dịch `index` sang phải 1 đơn vị (`index += 1`). Các số `0` sẽ tự động bị bỏ qua.
3. **Vòng lặp `for` thứ hai:** Bắt đầu từ vị trí `index` (nơi kết thúc chuỗi các số khác `0`) cho đến hết mảng (`num_element - 1`), gán toàn bộ các vị trí này bằng `0`.

## 4. Test Cases & Output

### Test Case 1: 
**Input:**
```text
9
6 0 8 2 3 0 4 0 1
```
**Output:**
```text
6 8 2 3 4 1 0 0 0 
```

### Test Case 2: 
**Input:**
```text
6
0 0 0 1 2 3
```
**Output:**
```text
1 2 3 0 0 0 
```

### Test Case 3: 
**Input:**
```text
4
0 0 0 0
```
**Output:**
```text
0 0 0 0 
```