package analyzer;

import java.util.LinkedList;
import java.util.Iterator;

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
public class AnalyzerCore {
    String Str;
    long seed = 0;

    public AnalyzerCore(String str) {
        super();
        this.Str = str;
    }

    public String doAnalyze() {
        byte[] ch = Str.getBytes();
        this.seed = this.getCode(ch);
        LinkedList list = new LinkedList();
        int left = 100;
        do {
            int Kind = (int) rnd() % 100;
            Iterator it = list.listIterator();
            boolean same = false;
            while (it.hasNext()) {
                /*同じのがあればもう一回試す*/
                if (((Element) it.next()).getKind() == Kind) {
                    same |= true;
                }
            }
            if (same) {
                continue;
            }
            Element elt = new Element(Str, Kind,
                                      (int) (rnd() % left) + 1);
            left -= elt.getParcentage();
            list.add(elt);
        } while (left > 0);
        Object obj[] = list.toArray();
        Element[] comp = new Element[obj.length];
        for (int i = 0; i < comp.length; i++) {
            comp[i] = (Element) obj[i];
        }

        selectionSort(comp, 0, comp.length);
        return getString(comp);
    }

    public String getString(Element[] list) {
        String ret = "";
        boolean before = false;
        ret += this.Str + "の成分解析結果 : \n\n";
        for (int i = 0; i < list.length; i++) {
            ret += list[i].toString(before);
            if (list[i].getParcentage() == 50) {
                before = true;
            }
        }
        return ret;
    }

    public void selectionSort(Element[] elt, int start, int end) {
        for (int i = end - 1; i > start; i--) {
            int prev = 0;
            for (int j = start + 1; j <= i; j++) {
                if (!(elt[prev].getParcentage() <= elt[j].getParcentage())) {
                    prev = j;
                }
            }
            swap(elt, i, prev);
        }
    }

    public void qsort(Element[] elt, int start, int length) {
        int end = start+length-1;
        do {
            if (!(length > 8)) {
                selectionSort(elt, start, length);
            } else {
                /*個数を２で割って入れ替え*/
                swap(elt, start, start + (length >> 1));
                int a;
                int b = start + length - 1;
                while (true) {
                    b++;//なぜか足す
                    //最初の要素からサーチ
                    a = start;
                    do {
                        a++;
                    }while(!(compare(elt[a], elt[start]) <= 0) && !(a > end));
                    //最後の要素からサーチ
                    do {
                        b--;
                    }while(!(compare(elt[b], elt[start]) >= 0) && !(b < start));

                    if(b < a){
                        break;
                    }else{
                        swap(elt,a,b);
                        continue;
                    }
                }
                swap(elt,start,b);
                if(!((b-start-1) < (end - a))){

                }else{
                    if(!(b > start + 1)){
                        b--;
                        if(!(a > end)){
                            break;
                        }else{
                            start = a;
                            continue;
                        }
                    }else{

                    }
                }
            }
        } while (true);

    }

    public int compare(Element a, Element b) {
        if (a.getParcentage() < b.getParcentage()) {
            return -1;
        } else if (a.getParcentage() < b.getParcentage()) {
            return 1;
        } else {
            return 0;
        }
    }

    public void swap(Element elt[], int target1, int target2) {
        Element tmp;
        tmp = elt[target2];
        elt[target2] = elt[target1];
        elt[target1] = tmp;
    }

    public long getCode(byte[] ch) {
        long code = 0;
        for (int i = 0; i < ch.length; i++) {
            int add = psi.lib.CalTools.PokeTools.ByteToInt(ch[i]);
            code += add << ((i & 0x80000003) << 3);
        }
        code <<= 32;
        code >>= 32;
//        code &= 0xffffffff;
        return code;
    }

    public long rnd() {
        this.seed *= 0x343FD;
        this.seed += 0x269EC3;
        this.seed = this.seed << 32;
        this.seed = this.seed >> 32;
        long seed = this.seed;
        seed = seed >> 0x10;
        seed &= 0x7fff;
        //System.out.println(Long.toHexString(seed));
        return seed;
    }
}
