#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Queue.h"
#include "Variant6.h"
#include <stdlib.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Queue queue;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

//������ "�������" ��� �������
void __fastcall TForm1::CreateButtonClick(TObject *Sender)
{
	//�������� ������� �������
	queue.~Queue();
	ShowListBox->Clear();
	//���� �� ������ ������
	if (QueueSizeEdit->Text == "" || QueueSizeEdit->Text == "0")
	{
		Application->Title = "���������";
		ShowMessage("1. ������� \"������ �������\""
			"\n2. �������� �������� � ���� \"�������\""
			"\n3. ������� ������ \"�������\"");
	}   
	//���� ������ �� ������������� ���-�� ��������� ���������
	else if (AddQueueMemo->Lines->Count != StrToInt(QueueSizeEdit->Text))
	{
		Application->Title = "���������";
		ShowMessage("1. �������� �������� � ���� \"�������\""
			"\n2. �������� ���������� ��������� ���������"
			"\n3. ������� ������ \"�������\"");	
	}
	else
	{
		bool check = true;     //������������� ����� ������ ������
		int length = AddQueueMemo->Lines->Count;
		//�������� ����� ������ ������
		for (int i = 0; i < length; i++)
		{                                              
			if (AddQueueMemo->Lines->Strings[i] == "")
			{
				check = false;
			}
			int strLength = AddQueueMemo->Lines->Strings[i].Length();
			for (int j = 2; j <= strLength; j++)
			{
				if (AddQueueMemo->Lines->Strings[i][j] == '-')
					check = false;	
            }
		}
		if (!check)
		{
			Application->Title = "������";                
			ShowMessage("���� ������ �����");
		}
		else
		{
			for (int i = 0; i < length; i++)
			{
				int x = StrToInt(AddQueueMemo->Lines->Strings[i]);
				queue.Add(x);
			}
		}
		AddQueueMemo->Clear();
		ShowListBox->Clear();
		//PrintButtonClick(Sender);
	}
}

//������ "������"
void __fastcall TForm1::PrintButtonClick(TObject *Sender)
{
	ShowListBox->Clear();
	queue.Show(ShowListBox);
	if (ShowListBox->Items->Count == 0)
		ShowListBox->Items->Add("������� �����");
}

//������ "�������� � �����"
void __fastcall TForm1::AddToEndButtonClick(TObject *Sender)
{
	ShowListBox->Clear();
	if (AddElementEdit->Text != "")
	{
		ShowListBox->Clear();
		int x = StrToInt(AddElementEdit->Text);
		queue.Add(x);
		QueueSizeEdit->Text = IntToStr(StrToInt(QueueSizeEdit->Text) + 1);
		AddElementEdit->Text = "";
		PrintButtonClick(Sender);
	}
	else 
	{
		Application->Title = "���������";
		ShowMessage("������� ������� ��� ����������");
	}
}

//������ "������� �� ������"
void __fastcall TForm1::TakeFromBeginButtonClick(TObject *Sender)
{
	ShowListBox->Clear();
	queue.Delete(QueueSizeEdit);
	PrintButtonClick(Sender);
}

//������ "��������� �������"
void __fastcall TForm1::IsEmptyButtonClick(TObject *Sender)
{
   ShowListBox->Clear();
   queue.IsEmpty(QueueSizeEdit);
}

//������ "��������"
void __fastcall TForm1::CleanButtonClick(TObject *Sender)
{
	queue.~Queue();
	ShowListBox->Clear();
	QueueSizeEdit->Text = "0";
	Application->Title = "�������";
	ShowMessage("������� �����");	
}

//������� � Memo1 ��� ������� Enter ����� ����� ������� �������
void __fastcall TForm1::QueueSizeEditKeyPress(TObject *Sender, System::WideChar &Key)
{
	//���� ������ enter
	if(Key == VK_RETURN)
	{
		Key = 0;
		AddQueueMemo->SetFocus();
	}	
}

MyList myList;

//������ "�������" ��� ������
void __fastcall TForm1::MySolutionButtonClick(TObject *Sender)
{
	//�������� �������� ������
	myList.~MyList();
	ShowMyTaskListBox->Clear();
	//���� �� ������ ������
	if (ListSizeEdit->Text == "" || ListSizeEdit->Text == "0")
	{
		Application->Title = "���������";
		ShowMessage("������� \"������ ������\"");
	}
	else
	{
		Application->Title = "�������";
		ShowMessage("\t������� ����������� ������ �� ��������� ����� �����."
			" ������� ��� ������������� �������� ������");
		//��������� ����������
		int amount = StrToInt(ListSizeEdit->Text);
		randomize();
		for (int i = 0; i < amount; i++)
		{
			myList.Add(rand() % 101 - 50); //���������� ������� �� -50 �� 50
		}
		ShowMyTaskListBox->Items->Add("��������:");
		myList.Show(ShowMyTaskListBox);
		myList.RemoveMinus();
		ShowMyTaskListBox->Items->Add("��� �������.");
		ShowMyTaskListBox->Items->Add("���������:");
		myList.Show(ShowMyTaskListBox);
	}
}

//�������� �� ���� ����� � Memo1
void __fastcall TForm1::AddQueueMemoKeyPress(TObject *Sender, System::WideChar &Key)
{
	if ((Key >= '0' && Key <= '9') || Key == '-' || Key == VK_BACK 
		|| Key == VK_RETURN);
	else 
	{
		Key = '0';                                                 
		Application->Title = "������";                
		ShowMessage("���� ������ �����");
	}                                      	
}


