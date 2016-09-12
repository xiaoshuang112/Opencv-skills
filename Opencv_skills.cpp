void MoveandResizeWindow(CString window)
{
	  cvMoveWindow(SrcDlg, 0, 100);//确定图片位置，
   	cvResizeWindow(SrcDlg, 800, 320);//确定图片大小
}

void onMouse( int event, int x, int y, int, void*para )
{
	CFDetectionDlg *Cdlg = (CFDetectionDlg *)para;
	if(CV_EVENT_LBUTTONDOWN == event)
	{
	//	g_is_rect_inited = true;
		g_rect_tl = cvPoint(x, y);
		rect.x = x;
		rect.y = y;
		Cdlg->AddString(BLUE,"retc.x = %d,rect.y = %d",x, y);

	}

	else if (CV_EVENT_LBUTTONUP == event )
	{
		cvCopy(cvPhoto, copyPhoto);
		g_rect_br = cvPoint(x, y);
		cvRectangle(copyPhoto,g_rect_br,g_rect_tl, cvScalar(0,0,0), 5);


		cvShowImage(SrcDlg, copyPhoto);

		rect.height = abs(g_rect_tl.y - g_rect_br.y);
		rect.width  = abs(g_rect_tl.x - g_rect_br.x);
		Cdlg->AddString(BLUE,"rect.height = %d,rect.width = %d",rect.height, rect.width);
//����ROI �����ͷ�
		proPhoto = cvCreateImage(cvSize(rect.width,rect.height), 8, 3);

	 	cvSetImageROI(copyPhoto, rect); //set ROI,

		cvCopy(copyPhoto, proPhoto);
		cvResetImageROI(copyPhoto);
		//cvReleaseImage(&copyPhoto);
		//copyPhoto = NULL;

		cvShowImage(DstDlg, proPhoto);

		CTime time = ::GetCurrentTime();
		CString RecordTime;
		RecordTime.Format("%02d-%02d-%02d", time.GetHour(), time.GetMinute(), time.GetSecond());

		CString path =GetModulePath() + "JT\\" + RecordTime + ".jpg";
		cvSaveImage(path, proPhoto);

		cvReleaseImage(&proPhoto);
		proPhoto = NULL;
	}
}


//���÷�����cvSetMouseCallback( SrcDlg, onMouse, this);
