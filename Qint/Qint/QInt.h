#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

//Lưu ý: 
//github không push lên được hoặc có lỗi gì, có thể gửi drive nha, merge tay 
//Các hàm đảo string, tính toán, dùng hàm dựng sẵn không cần viết thêm
//Bit thứ n ( n từ 0 tới 127) thuộc bit thứ n%32 của qInt[3-n/32]
//Bit tính từ phải sang trái LSB là bit thứ 0 MSB là 127
//Bit 127 0 là dương, Bit 1 là âm
//int sang char là integer-48, char sang integer là char+48; hoặc dùng typecast
//Bool nhận 0 1 nhưng trả về cần typecast sang int để nhận đúng giá trị
//Hàm nào chưa nghĩ ra có thể lên bàn bạc với nhóm
//Phần quadruple số chấm động, báo cáo, app winform từ từ tính
//Bạn nào có ý kiên về thêm hàm hay gì thì báo với team nhé.



class QInt
{
private:

	// Lưu trữ qInt bằng mảng 4 phần tử (1 int là 4 byte)
	int qInt[4];

	// Set Bit 1
	// Nhận vị trí bit cần set, bit đó nằm trong phần tử nào ở mảng ( lưu ý dùng ct thầy cho là được)
	void SetBitOne(int BitPos,int qIntPos);

	//Set Bit 0 
	//Nhận vị trí bit cần set, bit đó nằm trong phần tử nào ở mảng ( lưu ý dùng ct thầy cho là được)
	void SetBitZero(int BitPos,int qIntPos);
	
	//Hàm cộng tính ra hệ 10
	string Add(string A,string B);

	//Biến xác định âm dương nhanh, không cần lấy bit đầu là 1 hay 0
	bool isNegative;

	//Bảng chuyển đổi từ Bin sang Hex bỏ vào chuỗi 4Bit vd "1111" output sẽ là F
	string HexValue(const string FourBit);
public:

	//Destructor
	~QInt();

	//Constructor cơ bản 
	// Có thể viết thêm vài constructor khác tiện cho debug
	QInt()
	{
		qInt[0] =0;
		qInt[1] = 0;
		qInt[2] = 0;
		qInt[3] = 0;
		isNegative = false;
	}

	//Trả dãy bit ở qInt thứ pos
	int getqInt(int pos)
	{
		return qInt[pos];
	}

	//Lấy giá trị âm hoặc dương của số
	bool getIsNegative();

	//Tính mũ 2 tại bit thứ n, vd n =7 tính 2^7 trả về string 128
	string PowerTwo(int BitPos);

	//Chia 2 1 lần, lấy được bit là số dư của phép chia trả về thương của phép chia cb cho lần chia tiếp
	string DivideTwo(string Input,int &bit);

	//Set bit tại vị trí thứ n, nhận vào giá trị bit 0 hoặc 1, dùng 2 hàm SetBit trên để cài đặt tiếp
	bool SetBit(int BitPosition,int BitValue);

	//Lấy bit tại vị trí cần lấy
	bool GetBit(int BitPosition);

	//Hàm nhập ( chưa rõ nhập gì, cần xử lý: nhập số âm, nhập rỗng, nhập sai. Cần nhận biết: nhập hệ 10, hệ 2, hệ 16 để xử lý việc lưu số xuống qInt ( đọc format file input của thầy, viết theo là được)
	void InputQint();

	//Xuất qInt dưới dạng thập phân (thầy nói rõ)
	void OutputQint();

	//Operator nhập, operator xuất, ( không quan trọng, thầy không yêu cầu)
	friend istream& operator >>(istream& in,QInt &qInt);
	friend ostream& operator <<(ostream& out, const QInt& qInt);

	//Xử lý số âm, bù 2, có thể dùng bù 1 rồi +1, hoặc pp LSB to MSB
	void TwoComplement();

	//Xử lý nhị phân sang thập lục phân  trả về chuỗi ( dùng hàm HexValue ở trên hoặc tự định nghĩa lại)
	string BinToHex();

	//Xử lý thập phân sang nhị phân, dùng hàm DivideTwo chia lấy bit ( có xử lý số âm)
	string DecToBin();

	//Xử lý nhị phân sang thập phân, dùng các hàm PowerTwo và Add để tiến hành ct hệ cơ số tổng quát ( có xử lý số âm)
	string BinToDec();
	
	//Xử lý chuyển từ thập lục phân sang nhị phân( có thể viết hàm trả về giá trị nhị phân 4bit)
	void HexToBin();


	//Các operator ( yêu cầu của thầy là xử lý trên bit nên sẽ dùng GetBit và SetBit để xử lý, không dùng hàm Add 2 số lớn ở trên)
	QInt operator + (QInt& qInt);
	QInt operator -(QInt& qInt);

	//2 thuật toán này phức tạp có thể để từ từ nghiên cứu
	QInt operator *(QInt& qInt);
	QInt operator /(QInt& qInt);

	//Các operator so sánh
	friend bool operator < (QInt& qInt1,QInt& qInt2);
	friend bool operator > (QInt& qInt1,QInt& qInt2);
	friend bool operator >= (QInt& qInt1, QInt& qInt2);
	friend bool operator <= (QInt& qInt1, QInt& qInt2);
	friend bool operator !=(QInt& qInt1, QInt& qInt2);
	friend bool operator == (QInt& qInt1,QInt& qInt2);
	
	
	//Operator gán (quan trọng,viết đầu tiên)
	QInt& operator = (const QInt& qInt);
	
	// Các operator and xor not dịch xoay,....
	QInt& operator &(QInt qInt);
	QInt& operator |(QInt qInt);
	QInt& operator ^(QInt qInt);
	QInt& operator ~();

	QInt& operator << (const int& Count);
	QInt& operator >>(const int& Count);

	void rol(const int& Turn);
	void ror(const int& Turn);

	

	// Đọc từ file của thầy lên để debug, để static
	static void ReadFromFile();

	//Ghi xuống file output.txt, để static
	static void WriteToFile();

	
};

