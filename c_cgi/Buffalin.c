#include <stdio.h>
#include <stdlib.h>

#ifndef NULL
#define NULL 0
#endif

const char *Kinds[] =  {"���S", "������", "�D�낳", "�ؗ킳", "���킢��", "�₳����", "��܂���",
                  "��炵��", "�ނȂ���", "�c���f��", "������", "���̖��킳", "�n�b�^��", "�r�^�~��",
                  "�w��", "�C��", "����", "����", "�H��", "��", "�d�g", "�œd�g", "���C��",
                  "���O", "���̂���������", "�����q", "�E�C", "�^", "�d��", "������",
                  "���Ɨ�(������)", "�o��", "��l�̓s��", "���h", "�~�]", "�R", "�^��", "���f",
                  "�M�O", "��", "�L��", "�S�̈ӎu", "�J���V�E��", "���@", "��]", "�s�v�c",
                  "����", "�x��", "�����S", "�", "�ԛ���", "�F���̈ӎv", "�]��", "�ŕ�", "��",
                  "�C��", "�ւ̔����k", "�g��", "����", "���", "�m��", "�m�b", "���̉�", "�Z��",
                  "�ۑ���", "���F��", "�ŋ�", "��", "��J", "���̎���", "������", "�X���C��",
                  "�A���R�[��", "����", "�ʕ�", "�ʘI", "���v", "�Ԃ�����", "��������", "�b�B",
                  "���̌�", "��H", "��]", "�A�d", "��̌���", "��", "���C���N", "���C���N",
                  "�J�e�L��", "�j��", "�C�̖���", "�}�C�i�X�C�I��", "�Z���_", "�~�X����", "���َq",
                  "���t", "�S�̕�", "�����̌�", "���_", "��", };

	const char* ThingName;
	char* EscapedThingName;
	unsigned int RndSeed = 0;
	int EltCount = 0;
	struct  Element{
		unsigned int kind;
		unsigned int per;
	} Elt[100];

char* escapeStr(const char* str,int length);

int main(){
	int result = 0;
	int length = 0;
	/*�Ƃ肠�����́D*/
	writeContentType();
	//���O�𓾂�
	getThingName();

	//�f�R�[�h����
	length = (int)strlen(ThingName);
	decode(ThingName,length);
	//�G�X�P�[�v������
	EscapedThingName = escapeStr(ThingName,length);

	result = doAnalyze(ThingName);
	writeHeader(EscapedThingName);//�w�b�_������
	writeTitle();//�^�C�g��
	writeForm(EscapedThingName);//�t�H�[��

	puts("<p>");
	if(result){
		writeResult(EscapedThingName);
	}else{
		writeError();
	}
	puts("</p>");
	writeAd();
	writeCounter();
	writeFooter();//�t�b�^
	free(EscapedThingName);//Free

	return 0;
}

char* escapeStr(const char* str,int length){
	int i;
	char* ret = malloc(length);
	int ret_i;
	int ret_length = length;
	for(i=0,ret_i=0;i<length;i++){
		char ch = str[i];
		switch(ch){
			case '<':
				ret_length+=4;
				ret = realloc(ret,ret_length);
				ret[ret_i+0]='&';
				ret[ret_i+1]='l';
				ret[ret_i+2]='t';
				ret[ret_i+3]=';';
				ret_i+=4;
				break;
			case '>':
				ret_length+=4;
				ret = realloc(ret,ret_length);
				ret[ret_i+0]='&';
				ret[ret_i+1]='g';
				ret[ret_i+2]='t';
				ret[ret_i+3]=';';
				ret_i+=4;
				break;
			case '&':
				ret_length+=5;
				ret = realloc(ret,ret_length);
				ret[ret_i+0]='&';
				ret[ret_i+1]='a';
				ret[ret_i+2]='m';
				ret[ret_i+3]='p';
				ret[ret_i+4]=';';
				ret_i+=5;
				break;
			case '\"':
				ret_length+=6;
				ret = realloc(ret,ret_length);
				ret[ret_i+0]='&';
				ret[ret_i+1]='q';
				ret[ret_i+2]='u';
				ret[ret_i+3]='o';
				ret[ret_i+4]='t';
				ret[ret_i+5]=';';
				ret_i+=6;
				break;
			case ' ':
				ret_length+=6;
				ret = realloc(ret,ret_length);
				ret[ret_i+0]='&';
				ret[ret_i+1]='n';
				ret[ret_i+2]='b';
				ret[ret_i+3]='s';
				ret[ret_i+4]='p';
				ret[ret_i+5]=';';
				ret_i+=6;
				break;
			default:
				ret[ret_i]=ch;
				ret_i++;
		}
	}
	return ret;
}

#define INDEX "Thing="

int getThingName(){
	char *input = getenv("QUERY_STRING");
	if(input == NULL || input[0] == '\0'){
		ThingName = "";
	}else{
		input = (char*)strstr(input,INDEX);
			if(input == NULL || input[0] == '\0'){
        		ThingName = "";
			}else{
        		ThingName = input + strlen(INDEX);
        	}
    }
        return 1;
}

int writeContentType(){
        puts("Content-type: text/html\n");
        return 0;
}

int writeHeader(char* thing){
		puts("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">");
		puts("<html lang=\"ja\"><head>");
		puts("<link rev=\"made\" href=\"http://ledyba.ddo.jp/\">");
		puts("<meta http-equiv=\"Content-Script-Type\" content=\"text/javascript\">");
		puts("<meta http-equiv=\"Content-Style-Type\" content=\"text/css\">");
		puts("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=Shift_JIS\">");
		puts("<title>�u������́v for CGI written in C");
		if(thing != NULL && thing[0] != '\0'){
			printf("�F%s�̉�͌���",thing);
        }
		puts("</title></head><body>");
	return 0;
}
int writeFooter(){
	puts("<hr>");
	puts("<p>");
	puts("Analyzed and written by <a href=\"http://ledyba.ddo.jp/\">�Ձi�v�T�C�j</a><br>");
	puts("Original program was written by <a href=\"http://www.tekipaki.jp/~clock/\">Clock</a><br>");
	puts("(2007/10/19)XSS�Ɏg�������ȐƎ㐫���C���B���p����Ȃ����ėǂ������B<br>");
	puts("���ł�HTML 4.01 Strict�Ɋ��S�����B������ˁI");
	puts("</p>");
    puts("</body></html>");
	return 0;
}

int writeTitle(){
	puts("<h1>�u������́v for CGI written in C</h1>");
	puts("<hr>");
	puts("<p>���s������������͂��C<a href=\"http://ledyba.ddo.jp/2006/03/28034103.php\">��͂���</a>C��CGI�ɈڐA���܂����D</p>");
	puts("<p> <a href=\"http://www.tekipaki.jp/~clock/\">�{��</a>��<a href=\"http://ledyba.ddo.jp/2006/04/04015951.php\">Java��</a>�Ɠ������ʂ��Ԃ�܂��D</p>");
	puts("<hr>");
	return 0;
}

int writeForm(char* thing){
	if(thing == NULL) thing = "";
	printf("<form method=\"GET\" action=\"%s\">\n",getenv("SCRIPT_NAME"));
	puts("<p>");
	printf("<input type=\"text\" name=\"Thing\" value=\"%s\" tabindex=\"1\" accesskey=\"1\">\n",thing);
	puts("<input type=\"submit\" value=\"��͂���\" tabindex=\"2\" accesskey=\"2\">");
	puts("<input type=\"reset\" value=\"���\" tabindex=\"3\" accesskey=\"3\">");
	puts("</p>");
	puts("</form>");
	puts("<hr>");
	return 0;
}

int doAnalyze(char* thing){
	unsigned int left = 100;
	unsigned int kind = 0;
	unsigned int per = 0;
	int i;
	int same;
	if(thing == NULL || thing[0] == '\0') return 0;
	RndSeed = getCode(thing);
	while(left > 0){
		kind = myRand() % 100;
		same = 0;
		for(i=0;i<EltCount;i++){
			if(Elt[i].kind == kind)same |= 1;
		}
		if(same) continue;
		per = (myRand() % left) + 1;
		Elt[EltCount].kind = kind;
		Elt[EltCount].per = per;
		left -= per;
		EltCount++;
	}
	sort();
	return 1;
}

int getCode(char* str){
	int i=0;
	unsigned int code = 0;
	for(;i<strlen(str);i++){
		code += (((int)str[i]) & 0xff) << ((i & 0x3)<<0x3);
//		printf("%x ",str[i]);
	}
	return code;
}

int myRand(){
	unsigned int result = 0;
	RndSeed *= 214013;
	RndSeed += 2531011; // ->���ɌĂяo���ꂽ�Ƃ���seed�Ɏg��
	result = RndSeed;
	result = result >> 0x10;
	result &= 0x7fff;
	return (unsigned int)result;
}

int sort(){
	int i,j;
	int prev;
	struct Element temp;
        for (i = EltCount - 1; i > 0; i--) {
        prev = 0;
            for (j = 1; j <= i; j++) {
                if (!(Elt[prev].per <= Elt[j].per)) {
                    prev = j;
                }
            }
            //swap(elt, i, prev);
            /*�X���b�v*/
	    temp = Elt[i];
	    Elt[i] = Elt[prev];
	    Elt[prev]=temp;
        }
}

int writeCounter(){
	puts("<script type=\"text/javascript\">");
	puts("var gaJsHost = ((\"https:\" == document.location.protocol) ? \"https://ssl.\" : \"http://www.\");");
	puts("document.write(unescape(\"%3Cscript src='\" + gaJsHost + \"google-analytics.com/ga.js' type='text/javascript'%3E%3C/script%3E\"));");
	puts("</script>");
	puts("<script type=\"text/javascript\">");
	puts("var pageTracker = _gat._getTracker(\"UA-4766333-1\");");
	puts("pageTracker._initData();");
	puts("pageTracker._trackPageview();");
	puts("</script>");
}

int writeResult(char* thing){
	int i;
	int before = 0;
	printf("%s�̐�����͌��� : <br>\n<br>\n",thing);
	for(i = 0;i<EltCount;i++){
	switch(Elt[i].per){
		case 50:
			if(!before){
				printf("%s�̔�����%s�ŏo���Ă��܂��B<br>\n",thing,Kinds[Elt[i].kind]);
				before |= 1;
			}else{
				printf("%s�̂���������%s�ŏo���Ă��܂��B<br>\n",thing,Kinds[Elt[i].kind]);
			}
			break;
		case 100:
			printf("%s�͂��ׂ�%s�ŏo���Ă��܂��B<br>\n",thing,Kinds[Elt[i].kind]);
			break;
		default:
			printf("%s��%d\%��%s�ŏo���Ă��܂��B<br>\n",thing,Elt[i].per,Kinds[Elt[i].kind]);
		}
	}
	return 0;
}
int writeError(){
	puts("�������̂���͂��Ă��������B");
	return 0;
}

int decode(char* s,int len){
        int i,j;
        char buf,*s1;
        if(len==0)return(-1);
        s1=(char*)malloc(len);
        for(i=0,j=0;i<len;i++,j++)
        {
                if(s[i]=='+'){s1[j]=' ';continue;}
                if(s[i]!='%') {s1[j]=s[i];continue;}
                buf=((s[++i]>='A') ? s[i]-'A'+10 : s[i]-'0');
                buf*=16;
                buf+=((s[++i]>='A') ? s[i]-'A'+10 : s[i]-'0');
                s1[j]=buf;
        }
        for(i=0;i<j;i++) s[i]=s1[i];
        s[i]='\0';
        free(s1);
        return(0);
}

int writeAd(){
	puts("<script type=\"text/javascript\"><!--");
	puts("google_ad_client = \"pub-3121031347596821\";");
	puts("google_ad_slot = \"5134098739\";");
	puts("google_ad_width = 234;");
	puts("google_ad_height = 60;");
	puts("//--></script>");
	puts("<script type=\"text/javascript\" src=\"http://pagead2.googlesyndication.com/pagead/show_ads.js\"></script>");
	return 0;
}
