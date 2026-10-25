# Longest Subarray with Unique Elements

## 1: Đề bài (Problem Statement)
**Problem:** Given an array of integers, find and print the longest contiguous subarray such that all elements in the subarray are distinct (no duplicate elements). If there are multiple subarrays of the same maximum length, print the first one found.

## 2: Thuật toán (Algorithm: cửa sổ trượt)

- Ta dùng một "cửa sổ" để quét qua mảng. Cửa sổ này được giới hạn bởi hai chỉ số: cạnh trái là `current_start` và cạnh phải là `i`.
- Ban đầu, ta mở rộng dần cửa sổ sang phải bằng cách tăng `i` để thêm các phần tử mới vào.
- Khi thêm một phần tử `arr[i]`, ta cần xét xem nó có bị trùng với bất kỳ phần tử nào đang nằm trong cửa sổ hiện tại (từ `current_start` đến `i-1`) hay không.
- Nếu **có phần tử trùng lặp** (giả sử ở vị trí `j`), ta phải loại bỏ các phần tử, kể từ phần tử ở vị trí `j` trở về sau ra khỏi cửa sổ bằng cách kéo cạnh trái `current_start` vượt qua vị trí `j` (tức là gán `current_start = j + 1`).
- Sau khi đảm bảo cửa sổ không còn phần tử trùng, ta đo chiều dài của cửa sổ hiện tại và cập nhật kỷ lục nếu nó dài hơn kỷ lục cũ.

<u> Lưu ý: </u>  **Chuong trình này chỉ in ra được 1 mảng con có độ dài lớn nhất. Nếu có nhiều mảng con thỏa mãn độ dài mỗi mảng đều đạt ngưỡng lớn nhất, thì ta chỉ in ra được mảng con đầu xuất hiện đầu tiên.** 

## 3: Code - Cách hoạt động của hàm find_subarr
- `best_max`: Lưu độ dài của mảng con dài nhất tìm được (kỷ lục).
- `best_start`: Lưu vị trí bắt đầu của mảng con dài nhất đó.
- `current_start`: Vị trí bắt đầu của mảng con đang xét ở thời điểm hiện tại.
- Vòng lặp `for` ngoài (`i` từ 0 đến `num_element - 1`): Duyệt qua từng phần tử của mảng đóng vai trò là cạnh phải của cửa sổ.
- Vòng lặp `for` trong (`j` từ `current_start` đến `i - 1`): Quét các phần tử bên trong cửa sổ để tìm xem có số nào bằng với số mới `arr[i]` không. 
    - Nếu tìm thấy `arr[j] == arr[i]`, ta cập nhật `current_start = j + 1` và `break` vòng lặp trong.
- `max_value = i - current_start + 1;`: Đo độ dài của cửa sổ hợp lệ hiện tại.
- Lệnh `if (best_max < max_value)`: So sánh để lưu lại kỷ lục `best_max` và `best_start`.
- Vòng lặp `for` cuối cùng: In ra các phần tử từ vị trí `best_start` với số lượng là `best_max`.

## 4: Test Cases & Output

**Test Case 1: **
- Input: 
  ```text
  8
  2 0 2 1 4 3 1 0
  ```
- Output: 
  ```text
  0 2 1 4 3 
  ```

**Test Case 2:**
- Input: 
  ```text
  5
  1 2 3 4 5
  ```
- Output: 
  ```text
  1 2 3 4 5 
  ```

**Test Case 3:**
- Input: 
  ```text
  4
  5 5 5 5
  ```
- Output: 
  ```text
  5 
  ```

**Test Case 4:**
- Input: 
  ```text
  6
  1 1 2 3 4 5
  ```
- Output: 
  ```text
  1 2 3 4 5 
  ```