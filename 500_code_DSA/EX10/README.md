# Đề bài (Problem Statement)

Given two sorted arrays, X[ ] and Y[ ] of size m and n each, merge elements of X[ ] with elements of array Y [ ] by maintaining the sorted order, i.e., fill X[ ] with the first m smallest elements and fill Y[ ] with remaining elements.
*(Do the conversion in-place and without using any other data structure.)*

# Thuật toán (Algorithm)

Ta có hai mảng đã được sắp xếp sẵn thứ tự tăng dần (theo chiều từ trái qua phải), do đó để output thu được là mảng X gồm $n$ phần tử bé nhất trong hai mảng (với $n$ là số phần tử của mảng X ban đầu), ta chỉ cần sử dụng 1 vòng lặp lặp qua các phần tử của X. 

Tại mỗi step trong vòng lặp, ta sẽ so sánh giá trị của phần tử đang xét trong mảng X (giả sử là $x$) với giá trị nhỏ nhất của mảng Y, hay phần tử đầu tiên của Y (giả sử là $y$):

* Nếu $x$ > $y$, ta sẽ thực hiện đổi chỗ hai phần tử này cho nhau. Sau đó ta cần sắp xếp lại thứ tự các phần tử trong mảng Y sao cho vẫn giữ được thứ tự các phần tử tăng dần từ trái qua phải.
* Nếu $x$ <= $y$, ta không thực hiện bất kì lệnh nào và chuyển sang xét phần tử khác.

# Code
Trong phần code, tôi có hai hàm chính:
1. `swap_two_element` sử dụng để đổi chỗ hai phần tử $x$ và $y$ như đã trình bày ở trên.
2. `merge_arr` là hàm thực hiện công việc chính: lặp qua các phần tử của mảng X $\rightarrow$ so sánh với phần tử đầu tiên của mảng Y $\rightarrow$ thực hiện đổi chỗ hai phần tử nếu thỏa mãn điều kiện $\rightarrow$ nếu có thực hiện đổi chỗ thì sắp xếp lại mảng Y theo đúng thứ tự ban đầu.

# Test case và Output
1. Test case 1: 
* Input:

        X[] = { 1, 4, 7, 8, 10 }

        Y[] = { 2, 3, 9 }

* Output:

        X[] = { 1, 2, 3, 4, 7 }

        Y[] = { 8, 9, 10 }

2. Test case 2:
* Input:

        X[] = { 1, 5, 9, 10, 15, 20 }

        Y[] = { 2, 3, 8, 13 }

* Output:

        X[] = { 1, 2, 3, 5, 8, 9 }

        Y[] = { 10, 13, 15, 20 }

3. Test case 3: 
* Input:

        X[] = { 10 }

        Y[] = { 2, 3 }

* Output:

        X[] = { 2 }

        Y[] = { 3, 10 }