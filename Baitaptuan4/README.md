# 1. Giải bài toán Tháp Hà Nội bằng thuật toán lặp (Iterative Tower of Hanoi)
## Giới thiệu
Đoạn code giải quyết bài toán Tháp Hà Nội kinh điển mà không sử dụng đệ quy (recursion). Thay vào đó, chương trình mô phỏng lại cấu trúc dữ liệu Ngăn xếp (Stack) bằng mảng 1 chiều và ứng dụng các quy luật toán học để dịch chuyển đĩa.
## Nguyên lý hoạt động của thuật toán
Với bài toán gồm n đĩa, ta phải thực hiện $2^n - 1$ bước di chuyển đĩa để chuyển toàn bộ n đĩa ở cột nguồn sang cột đích.

Do đó trong phần code, ta sẽ sử dụng vòng lặp $2^n - 1$ lần và đồng thời cần áp dụng một quy luật cho bài toán để xác định được tại mỗi vòng lặp, hai cột nào sẽ tương tác với nhau. Xét vòng lặp thứ i: 
- i chia 3 dư 1: tương tác giữa cọc nguồn(Source) và cọc đích (Des)
- i chia 3 dư 2: tương tác cọc nguồn (Source) và cọc trung gian (Helper) 
- i chia 3 dư 0: tương tác giữa cọc đích (Des) và cọc trung gian (Helper) 

**Lưu ý: Quy luật này áp dụng với tổng số đĩa là số lẻ, với tổng số đĩa là chẵn, ta chỉ cần đổi vai trò của cọc trung gian và cọc đích ngay từ đầu để đảm bảo toàn bộ số đĩa sẽ được hội tụ ở cọc đích.**

Khi đã biết được 2 cọc nào sẽ tương tác với nhau, ta cần xét đến vấn đề là nên chuyển đĩa từ cọc nào sang cọc nào để không vi phạm yêu cầu bài toán(đĩa to không được đặt lên trên đĩa bé). Giải quyết vấn đề này:
1. Quản lý cọc: Mỗi cọc sử dụng một mảng để lưu trữ giá trị các đĩa đang có (nếu cọc trống, đĩa mặc định coi là 0) và một biến chỉ số (index) trỏ tới vị trí trên cùng.
2. Lưu trạng thái đỉnh: Mảng current_state gồm 3 phần tử sẽ liên tục cập nhật kích thước của chiếc đĩa đang nằm trên cùng ở cả 3 cọc.
3. Thuật toán so sánh: Ta lấy giá trị đĩa trên cùng của hai cọc đang tương tác ra so sánh:
   - Nếu một trong hai cọc đang trống (đỉnh bằng 0), đĩa từ cọc có đĩa sẽ lập tức được chuyển sang cọc trống.  
   - Nếu cả hai cọc đều có đĩa, chiếc đĩa có giá trị nhỏ hơn sẽ được lấy ra (pop) và chuyển sang nằm đè lên chiếc đĩa lớn hơn (push).

## Cấu trúc code
Các hàm chính:
- `interact_peg`: Hàm thực hiện thao tác vật lý lấy đĩa và đặt đĩa. Hàm sử dụng con trỏ (pointer) để thao tác trực tiếp vào mảng ngăn xếp, cập nhật lại chỉ số đỉnh cọc và trạng thái của đĩa trên cùng
- `solve_HNtower`: Hàm trung tâm chịu trách nhiệm khởi tạo trạng thái ban đầu, kiểm tra chẵn/lẻ để đổi cọc, và thực thi vòng lặp $2^n - 1$ bước
- `main`: Hàm khởi chạy, định nghĩa số lượng đĩa $n$ và gán nhãn cho các cọc (Ví dụ: A, B, C)


# 2. Giải bài toán Tháp Hà Nội bằng thuật toán đệ quy (Recursion Tower of Hanoi)
# Giải bài toán Tháp Hà Nội bằng Đệ quy (Recursive Tower of Hanoi)

## Giới thiệu
Dự án này triển khai mã nguồn C để giải quyết bài toán Tháp Hà Nội bằng phương pháp Đệ quy (Recursion). Trái ngược với phương pháp lặp (mô phỏng ngăn xếp và tính toán chu kỳ), phương pháp đệ quy giải quyết vấn đề bằng cách chia một bài toán lớn thành các bài toán con tương tự nhưng với quy mô nhỏ hơn.

## Nguyên lý hoạt động của thuật toán
Ý tưởng của đệ quy trong bài toán Tháp Hà Nội gồm $n$ đĩa là quy về việc di chuyển $n-1$ đĩa. Cụ thể, để chuyển toàn bộ $n$ đĩa từ cọc Nguồn (Source) sang cọc Đích (Destination) với sự trợ giúp của cọc Phụ (Helper), thuật toán thực hiện 3 bước sau:

1.  **Bước 1:** Di chuyển phần ngọn gồm $n-1$ đĩa từ cọc Nguồn sang cọc Phụ. Lúc này, chiếc đĩa lớn nhất (đĩa thứ $n$) ở cọc nguồn đã có thể được tự do di chuyển.
2.  **Bước 2:** Di chuyển chiếc đĩa lớn nhất (đĩa thứ $n$) từ cọc Nguồn sang cọc Đích.
3.  **Bước 3:** Di chuyển lại $n-1$ đĩa từ cọc Phụ sang cọc Đích để hoàn thành tháp.

Quá trình này lặp lại liên tục (hàm tự gọi lại chính nó) cho đến khi số đĩa giảm xuống mức tối thiểu (Trường hợp cơ sở - Base Case), lúc đó thuật toán không cần chia nhỏ nữa mà thực hiện di chuyển trực tiếp.

## Cấu trúc Code
Các hàm chính:

*   **Hàm `solveTower`:** Đây là hàm đệ quy xử lý logic di chuyển đĩa. Nó nhận 4 tham số: số lượng đĩa hiện tại và tên của 3 cọc. Hàm chia làm 3 nhánh xử lý:
    *   **Trường hợp `num_dish == 1`:** Đây là trường hợp cơ sở nhỏ nhất. Trường hợp này chỉ cần chuyển trực tiếp đĩa từ nguồn sang đích là hoàn thành.
    *   **Trường hợp `num_dish == 2`:** 3 thao tác di chuyển lần lượt (Nguồn $\rightarrow$ Phụ, Nguồn $\rightarrow$ Đích, Phụ $\rightarrow$ Đích).
    *   **Trường hợp `num_dish > 2` (Nhánh `else`):** Hàm thực hiện gọi đệ quy chính nó 3 lần, bám sát đúng 3 bước của nguyên lý "Chia để trị" đã nêu ở trên. Bước chuyển chiếc đĩa lớn nhất ở giữa cũng được mô phỏng bằng một lời gọi hàm đệ quy với tham số `1` đĩa.

*   **Hàm `main`:** Hàm khởi chạy, định nghĩa số lượng đĩa n và gán nhãn cho các cọc (Ví dụ: A, B, C)

# 3. Kiểm chứng (Test case)
Dưới đây là các test case tiêu biểu để kiểm chứng tính đúng đắn của thuật toán. Với cả cách sử dụng vòng lặp và cách sử dụng đệ quy đều cho ra một output giống nhau khi cùng số lượng đĩa đầu vào
## Test case 1: Tháp 2 đĩa
Input: 2

Output:
- Pop dish from A, push into C
- Pop dish from A, push into B
- Pop dish from C, push into B

## Test case 2: Tháp 3 đĩa
Input: 3

Output:
- Pop dish from A, push into B
- Pop dish from A, push into C
- Pop dish from B, push into C
- Pop dish from A, push into B
- Pop dish from C, push into A
- Pop dish from C, push into B
- Pop dish from A, push into B