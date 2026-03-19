# OSG
## Thuật toán FCFS (First Come First Served)
### 1. Giới thiệu
- Chương trình này mô phỏng thuật toán FCSFS
- Nguyên tắc: Tiến trình nào đến trước sẽ được xử lý trước
- Là thuật toán non-preemptive (không có ngắt)
### 2. Thuật toán
- Đọc số lượng tiến trình n từ file input.txt
- Đọc arrivalTime (Thời điểm đến) và burstTime (Thời gian xử lý) cho từng tiến trình
- Sắp xếp các tiến trình theo thời gian đến
- Duyệt từng tiến trình:
  + Nếu CPU rảnh thì cập nhật currentTime
  + Tính:
    - Waiting Time (WT)
    - Completion Time (CT)
    - Turnaround Time (TAT)
### 3. Định dạng file input.txt
- File input.txt có dạng:
  n
  arrival_time_1 burst_time_1
  arrival_time_2 burst_time_2
  ...
  arrival_time_n burst_time_n
- Giải thích:
  + n là số tiến trình
  + arrival_time_n là thời điểm đến của tiến trình n
  + burst_time_n là thời gian xử lý của tiến trình n
- Ví dụ:
  ```
  3
  0 5
  0 3
  0 8
### 4. Định dạng file output.txt
- File output.txt gồm các côt:
  PID  AT  BT  WT  TAT  CT
- Trong đó:
  + PID: ID tiến trình
  + AT (Arrival Time): Thời điểm đến
  + BT (Burst Time): Thời gian xử lý
  + WT (Waiting Time): Thời gian chờ
  + TAT (Turnaround Time): Thời gian hoàn thành
  + CT (Completion Time): Thời điểm hoàn thành
- Ví dụ:
  ```
  PID	AT	BT	WT	TAT	CT
  P1  0   5   0   5   5
  P2  0   3   5   8   8
  P3  0   8   8   16  16
### 5. Cách chạy chương trình
- Chuẩn bị file input.txt
- Compile: g++ FCFS.cpp -o FCFS.exe
- Chạy: ./fcfs.exe
- Kết quả sẽ được ghi vào output.txt

## Thuật toán SJF (Shortest Job First)
### 1. Giới thiệu
- Chương trình này mô phỏng thuật toán SJF
- Nguyên tắc: Chọn tiến trình có burst time nhỏ nhất để thực thi trước
- Là thuật toán non-preemptive (không có ngắt)
### 2. Thuật toán
- Đọc số lượng tiến trình n từ file input.txt
- Đọc arrivalTime và burstTime
- Lặp cho đến khi tất cả tiến trình hoàn thành:
  + Tìm tiến trình:
    - Đã đến (arrivalTime <= currentTime)
    - Chưa hoàn thành
    - Có burst time nhỏ nhất
  + Nếu chưa có tiến trình nào đến thì tăng currentTime
  + Ngược lại:
    - Tính waitingTime
    - Cập nhật currentTime
    - Tính completionTime, turnaroundTime
- Ghi kết ra file output.txt
### 3. Định dạng file input.txt
- File input.txt có dạng:
  n
  arrival_time_1 burst_time_1
  arrival_time_2 burst_time_2
  ...
  arrival_time_n burst_time_n
- Giải thích:
  + n là số tiến trình
  + arrival_time_n là thời điểm đến của tiến trình n
  + burst_time_n là thời gian xử lý của tiến trình n
- Ví dụ:
  ```
  4
  0 8
  1 4
  2 2
  3 1
### 4. Định dạng file output.txt
- File output.txt gồm các côt:
  PID  AT  BT  WT  TAT  CT
- Trong đó:
  + PID: ID tiến trình
  + AT (Arrival Time): Thời điểm đến
  + BT (Burst Time): Thời gian xử lý
  + WT (Waiting Time): Thời gian chờ
  + TAT (Turnaround Time): Thời gian hoàn thành
  + CT (Completion Time): Thời điểm hoàn thành
- Ví dụ:
  ```
  PID	AT	BT	WT	TAT	CT
  P1	0	  8	  0	  8	  8
  P2	1	  4	  10	14	15
  P3	2	  2	  7	  9	  11
  P4	3	  1	  5	  6	  9
### 5. Cách chạy chương trình
- Chuẩn bị file input.txt
- Compile: g++ SJF.cpp -o SJF.exe
- Chạy: ./SJF.exe
- Kết quả sẽ được ghi vào output.txt

## Thuật toán SRTF (Shortest Remaining Time First)
### 1. Giới thiệu
- Chương trình này mô phỏng thuật toán SRTF
- Nguyên tắc: Luôn chọn tiến trình có thời gian còn lại nhỏ nhất
- Là thuật toán preemptive (có ngắt), phiên bản có ngắt của SJF
### 2. Thuật toán
- Đọc số lượng tiến trình n từ file input.txt
- Đọc arrivalTime và burstTime
- Lặp cho đến khi tất cả tiến trình hoàn thành:
  + Tại mỗi thời điểm, tìm tiến trình:
    - Đã đến (arrivalTime <= currentTime)
    - remainingTime > 0
    - Có remaining time nhỏ nhất
  + Nếu chưa có tiến trình nào thì tăng currentTime
  + Ngược lại:
    - Chạy tiến trình 1 đơn vị thời gian
    - Giảm remainingTime
    - Nếu hoàn thành: Tính completionTime, turnaroundTime, waitingTime
  ### 3. Định dạng file input.txt
  - File input.txt có dạng:
  n
  arrival_time_1 burst_time_1
  arrival_time_2 burst_time_2
  ...
  arrival_time_n burst_time_n
- Giải thích:
  + n là số tiến trình
  + arrival_time_n là thời điểm đến của tiến trình n
  + burst_time_n là thời gian xử lý của tiến trình n
- Ví dụ:
  ```
  4
  0 8
  1 4
  2 2
  3 1
  ### 4. Định dạng file output.txt
- File output.txt gồm các côt:
  PID  AT  BT  WT  TAT  CT
- Trong đó:
  + PID: ID tiến trình
  + AT (Arrival Time): Thời điểm đến
  + BT (Burst Time): Thời gian xử lý
  + WT (Waiting Time): Thời gian chờ
  + TAT (Turnaround Time): Thời gian hoàn thành
  + CT (Completion Time): Thời điểm hoàn thành
- Ví dụ:
  ```
  PID	AT	BT	WT	TAT	CT
  P1	0	  8	  7	  15	15
  P2	1	  4	  3	  7	  8
  P3	2	  2	  0	  2	  4
  P4	3	  1	  1	  2	  5
### 5. Cách chạy chương trình
- Chuẩn bị file input.txt
- Compile: g++ SRTF.cpp -o SRTF.exe
- Chạy: ./SRTF.exe
- Kết quả sẽ được ghi vào output.txt

## Thuật toán Priority Scheduling
### 1. Giới thiệu
- Chương trình này mô phỏng thuật toán Priority Scheduling
- Nguyên tắc: Tiến trình có priority cao hơn sẽ được chạy trước
- Là thuật toán non-preemptive (không có ngắt)
### 2. Thuật toán
- Đọc số lượng tiến trình n từ file input.txt
- Đọc arrivalTime, burstTime và priority
- Lặp cho đến khi hoàn thành tất cả tiến trình:
  + Tìm tiến trình:
    - Đã đến (arrivalTime <= currentTime)
    - Chưa hoàn thành
    - Có priority nhỏ nhất
  + Nếu chưa có tiến trình nào thì tăng currentTime
  + Ngược lại:
    - Tính waitingTime
    - Cập nhật currentTime
    - Tính completionTime, turnaroundTime
### 3. Định dạng file input.txt
  - File input.txt có dạng:
  n
  arrival_time_1 burst_time_1 priority
  arrival_time_2 burst_time_2 priority
  ...
  arrival_time_n burst_time_n priority
- Giải thích:
  + n là số tiến trình
  + arrival_time_n là thời điểm đến của tiến trình n
  + burst_time_n là thời gian xử lý của tiến trình n
  + priority là độ ưu tiên
- Ví dụ:
  ```
  4
  0 6 3
  0 2 1
  0 8 4
  0 3 2
### 4. Định dạng file output.txt
- File output.txt gồm các côt:
  PID  AT  BT  PR  WT  TAT  CT
- Trong đó:
  + PID: ID tiến trình
  + AT (Arrival Time): Thời điểm đến
  + BT (Burst Time): Thời gian xử lý
  + PR: độ ưu tiên
  + WT (Waiting Time): Thời gian chờ
  + TAT (Turnaround Time): Thời gian hoàn thành
  + CT (Completion Time): Thời điểm hoàn thành
- Ví dụ:
  ```
  PID	AT	BT	PR	WT	TAT	CT
  P1	0	  6	  3	  5	  11	11
  P2	0	  2	  1	  0	  2	  2
  P3	0	  8	  4	  11	19	19
  P4	0	  3	  2	  2	  5	  5
### 5. Cách chạy chương trình
- Chuẩn bị file input.txt
- Compile: g++ PS.cpp -o PS.exe
- Chạy: ./PS.exe
- Kết quả sẽ được ghi vào output.txt

## Thuật toán Round Robin
### 1. Giới thiệu
- Chương trình này mô phỏng thuật toán Round Robin (RR)
- Nguyên tắc:
  + Mỗi tiến trình được cấp CPU trong 1 khoảng thời gian cố định gọi là time quantum
  + Nếu chưa hoàn thành thì bị đưa xuống cuối hàng đợi
- Là thuật toán preemptive (có ngắt)
### 2. Thuật toán
- Đọc số lượng tiến trình n từ file input.txt
- Đọc arrivalTime và burstTime
- Đọc time quantum
- Sử dụng queue để quản lý tiến trình
- Lặp cho đến khi hoàn thành tất cả:
  + Thêm các tiến trình đã đến vào queue
  + Nếu queue rỗng thì tăng currentTime
  + Lấy tiến trình đầu queue:
    - Chạy trong min(quantum, remainingTime)
    - Giảm remainingTime
  + Nếu chưa xong thì đưa lại queue
  + Nếu xong: Tính completionTime, turnaroundTime và waitingTime
### 3. Định dạng file input.txt
  - File input.txt có dạng:
  n
  arrival_time_1 burst_time_1
  arrival_time_2 burst_time_2
  ...
  arrival_time_n burst_time_n
  quantum
- Giải thích:
  + n là số tiến trình
  + arrival_time_n là thời điểm đến của tiến trình n
  + burst_time_n là thời gian xử lý của tiến trình n
  + quantum là số thời gian cấp CPU mỗi tiến trình
- Ví dụ:
  ```
  3
  0 5
  0 4
  0 2
  2
### 4. Định dạng file output.txt
- File output.txt gồm các côt:
  PID  AT  BT  WT  TAT  CT
- Trong đó:
  + PID: ID tiến trình
  + AT (Arrival Time): Thời điểm đến
  + BT (Burst Time): Thời gian xử lý
  + WT (Waiting Time): Thời gian chờ
  + TAT (Turnaround Time): Thời gian hoàn thành
  + CT (Completion Time): Thời điểm hoàn thành
- Ví dụ:
  ```
  PID	AT	BT	WT	TAT	CT
  P1	0	  5	  6	  11	11
  P2	0	  4	  6	  10	10
  P3	0	  2	  4	  6	  6
### 5. Cách chạy chương trình
- Chuẩn bị file input.txt
- Compile: g++ RR.cpp -o RR.exe
- Chạy: ./RR.exe
- Kết quả sẽ được ghi vào output.txt
