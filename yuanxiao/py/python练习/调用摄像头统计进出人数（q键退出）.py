import cv2

# 加载Haar级联分类器
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

# 从摄像头获取视频流
cap = cv2.VideoCapture(0)  # 0表示默认摄像头

# 定义感兴趣区域的坐标
roi_x, roi_y, roi_w, roi_h = 100, 100, 300, 200

# 初始化人数计数
enter_count = 0
exit_count = 0

while True:
    # 读取视频流
    ret, frame = cap.read()
    if not ret:
        break

    # 截取感兴趣区域
    roi = frame[roi_y:roi_y+roi_h, roi_x:roi_x+roi_w]

    # 将感兴趣区域转为灰度图像
    gray_roi = cv2.cvtColor(roi, cv2.COLOR_BGR2GRAY)

    # 使用Haar级联分类器检测人脸
    faces = face_cascade.detectMultiScale(gray_roi, scaleFactor=1.3, minNeighbors=5)

    # 绘制人脸框
    for (x, y, w, h) in faces:
        cv2.rectangle(roi, (x, y), (x+w, y+h), (255, 0, 0), 2)

    # 人数计数逻辑
    for (x, y, w, h) in faces:
        # 假设人脸中心点在感兴趣区域中心，根据人脸位置判断进入或离开
        face_center = (x + w // 2, y + h // 2)
        roi_center = (roi_w // 2, roi_h // 2)

        if face_center[0] < roi_center[0]:
            exit_count += 1
        else:
            enter_count += 1

    # 在图像上显示人数信息
    cv2.putText(frame, f"Enter: {enter_count}", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
    cv2.putText(frame, f"Exit: {exit_count}", (10, 70), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)

    # 显示图像
    cv2.imshow('People Counting', frame)

    # 检测键盘输入，按'q'退出循环
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# 释放资源
cap.release()
cv2.destroyAllWindows()
