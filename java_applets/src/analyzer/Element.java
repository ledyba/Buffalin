package analyzer;

/**
 * <p>タイトル: 成分解析</p>
 *
 * <p>説明: 成分を解析します</p>
 *
 * <p>著作権: Copyright (c) 2006 PSI</p>
 *
 * <p>会社名: ψ（プサイ）の興味関心空間</p>
 *
 * @author 未入力
 * @version 1.0
 */
public class Element {
    private int Kind;
    private int Parcentage;
    String[] Kinds = {"下心", "微妙さ", "優雅さ", "華麗さ", "かわいさ", "やさしさ", "やましさ",
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
    private String Thing;
    public Element(String thing,int Kind,int Parcentage) {
        super();
        this.Thing = thing;
        this.Kind = Kind;
        this.Parcentage = Parcentage;
    }

    public int getKind() {
        return Kind;
    }

    public int getParcentage() {
        return Parcentage;
    }
    public String toString(boolean before){
        switch(Parcentage){
        case 50:
            if(before){
            return Thing+"もう半分は"+this.Kinds[Kind]+"で出来ています。\n";
            }else{
                return Thing+"の半分は"+this.Kinds[Kind]+"で出来ています。\n";
            }
        case 100:
            return Thing+"はすべて"+this.Kinds[Kind]+"で出来ています。\n";
        default:
            return Thing+"の"+Parcentage+"%は"+this.Kinds[Kind]+"で出来ています。\n";
        }
    }
}
