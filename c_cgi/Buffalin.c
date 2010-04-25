#include <stdio.h>
#include <stdlib.h>

#ifndef NULL
#define NULL 0
#endif

const char *Kinds[] =  {"下心", "微妙さ", "優雅さ", "華麗さ", "かわいさ", "やさしさ", "やましさ",
                  "やらしさ", "むなしさ", "ツンデレ", "厳しさ", "世の無常さ", "ハッタリ", "ビタミン",
                  "努力", "気合", "根性", "砂糖", "食塩", "愛", "電波", "毒電波", "元気玉",
                  "怨念", "大阪のおいしい水", "明太子", "勇気", "運", "電力", "小麦粉",
                  "汗と涙(化合物)", "覚悟", "大人の都合", "見栄", "欲望", "嘘", "真空", "呪詛",
                  "信念", "夢", "記憶", "鉄の意志", "カルシウム", "魔法", "希望", "不思議",
                  "勢い", "度胸", "乙女心", "罠", "花崗岩", "宇宙の意思", "犠牲", "毒物", "鉛",
                  "海水", "蛇の抜け殻", "波動", "純金", "情報", "知識", "知恵", "魂の炎", "媚び",
                  "保存料", "着色料", "税金", "歌", "苦労", "柳の樹皮", "睡眠薬", "スライム",
                  "アルコール", "時間", "果物", "玉露", "利益", "赤い何か", "白い何か", "鍛錬",
                  "月の光", "回路", "野望", "陰謀", "雪の結晶", "株", "黒インク", "白インク",
                  "カテキン", "祝福", "気の迷い", "マイナスイオン", "濃硫酸", "ミスリル", "お菓子",
                  "言葉", "心の壁", "成功の鍵", "理論", "血", };

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
	/*とりあえずは．*/
	writeContentType();
	//名前を得る
	getThingName();

	//デコードする
	length = (int)strlen(ThingName);
	decode(ThingName,length);
	//エスケープもする
	EscapedThingName = escapeStr(ThingName,length);

	result = doAnalyze(ThingName);
	writeHeader(EscapedThingName);//ヘッダを書く
	writeTitle();//タイトル
	writeForm(EscapedThingName);//フォーム

	puts("<p>");
	if(result){
		writeResult(EscapedThingName);
	}else{
		writeError();
	}
	puts("</p>");
	writeAd();
	writeCounter();
	writeFooter();//フッタ
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
		puts("<title>「成分解析」 for CGI written in C");
		if(thing != NULL && thing[0] != '\0'){
			printf("：%sの解析結果",thing);
        }
		puts("</title></head><body>");
	return 0;
}
int writeFooter(){
	puts("<hr>");
	puts("<p>");
	puts("Analyzed and written by <a href=\"http://ledyba.ddo.jp/\">ψ（プサイ）</a><br>");
	puts("Original program was written by <a href=\"http://www.tekipaki.jp/~clock/\">Clock</a><br>");
	puts("(2007/10/19)XSSに使えそうな脆弱性を修正。悪用されなくって良かった。<br>");
	puts("ついでにHTML 4.01 Strictに完全準拠。やったね！");
	puts("</p>");
    puts("</body></html>");
	return 0;
}

int writeTitle(){
	puts("<h1>「成分解析」 for CGI written in C</h1>");
	puts("<hr>");
	puts("<p>流行だった成分解析を，<a href=\"http://ledyba.ddo.jp/2006/03/28034103.php\">解析して</a>CのCGIに移植しました．</p>");
	puts("<p> <a href=\"http://www.tekipaki.jp/~clock/\">本家</a>や<a href=\"http://ledyba.ddo.jp/2006/04/04015951.php\">Java版</a>と同じ結果が返ります．</p>");
	puts("<hr>");
	return 0;
}

int writeForm(char* thing){
	if(thing == NULL) thing = "";
	printf("<form method=\"GET\" action=\"%s\">\n",getenv("SCRIPT_NAME"));
	puts("<p>");
	printf("<input type=\"text\" name=\"Thing\" value=\"%s\" tabindex=\"1\" accesskey=\"1\">\n",thing);
	puts("<input type=\"submit\" value=\"解析する\" tabindex=\"2\" accesskey=\"2\">");
	puts("<input type=\"reset\" value=\"取消\" tabindex=\"3\" accesskey=\"3\">");
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
	RndSeed += 2531011; // ->次に呼び出されたときのseedに使う
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
            /*スワップ*/
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
	printf("%sの成分解析結果 : <br>\n<br>\n",thing);
	for(i = 0;i<EltCount;i++){
	switch(Elt[i].per){
		case 50:
			if(!before){
				printf("%sの半分は%sで出来ています。<br>\n",thing,Kinds[Elt[i].kind]);
				before |= 1;
			}else{
				printf("%sのもう半分は%sで出来ています。<br>\n",thing,Kinds[Elt[i].kind]);
			}
			break;
		case 100:
			printf("%sはすべて%sで出来ています。<br>\n",thing,Kinds[Elt[i].kind]);
			break;
		default:
			printf("%sの%d\%は%sで出来ています。<br>\n",thing,Elt[i].per,Kinds[Elt[i].kind]);
		}
	}
	return 0;
}
int writeError(){
	puts("物質名称を入力してください。");
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
