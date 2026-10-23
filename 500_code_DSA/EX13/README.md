# Find the Maximum Product of Two Integers in an Array

## 1. Đề bài (Problem Statement)
Given an integer array, find the maximum product of two integers in it.

## 2. Thuật toán (Algorithm)
Khi mảng chứa cả số nguyên âm và số nguyên dương, tích lớn nhất của hai số bất kỳ chỉ có thể rơi vào một trong hai trường hợp: tích của hai số lớn nhất trong mảng hoặc tích của hai số nhỏ nhát trong mảng. Do đó ta chỉ cần sắp xếp lại mảng là đã gần như hoàn thành bài toán.

**Các bước thực hiện:**
* **Bước 1:** Sử dụng thuật toán **Merge Sort** để sắp xếp mảng theo thứ tự tăng dần.
* **Bước 2:** So sánh tích của hai phần tử đầu tiên (`arr[0] * arr[1]`) với tích của hai phần tử cuối cùng (`arr[n - 2] * arr[n - 1]`) để tìm ra cặp số cho tích lớn nhất và in kết quả tương ứng.

## 3. Code & Giải thích thuật toán

### Cách hoạt động:
1. **Hàm `merge_sort(arr, left, right)`:** Chia đôi mảng đệ quy liên tục dựa trên chỉ số `mid = (left + right) / 2` cho đến khi các mảng con chỉ còn 1 phần tử (`left >= right`).
2. **Hàm `merge_part(arr, left, mid, right)`:** Trộn hai nửa mảng con đã sắp xếp (`[left ... mid]` và `[mid + 1 ... right]`) vào mảng tạm `tmp[]` theo thứ tự tăng dần, sau đó sao chép ngược lại vào mảng chính `arr[]`.
3. **Xử lý kết quả trong `main()`:** 
   * Sau khi mảng được sắp xếp tăng dần, ta tính toán và đối chiếu tích của hai phần tử đầu (`arr[0] * arr[1]`) và hai phần tử cuối (`arr[num_arr - 2] * arr[num_arr - 1]`).
   * In ra cặp số tương ứng cho ra tích lớn nhất (hoặc in cả hai cặp nếu tích của chúng bằng nhau).

## 4. Test Cases & Output

### Test Case 1:
**Input:**
```text
5
-10 -3 5 6 -2
```
**Output:**
```text
Pair is: (-10, -3)
```

### Test Case 2:
**Input:**
```text
4
-4 -3 3 4
```
**Output:**
```text
Pair is: (-4, -3); (3, 4)
```

### Test Case 3: 
**Input:**
```text
5
-4 1 3 7 9
```
**Output:**
```text
Pair is: (7, 9)
```