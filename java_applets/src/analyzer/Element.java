package analyzer;

/**
 * <p>�^�C�g��: �������</p>
 *
 * <p>����: ��������͂��܂�</p>
 *
 * <p>���쌠: Copyright (c) 2006 PSI</p>
 *
 * <p>��Ж�: �Ձi�v�T�C�j�̋����֐S���</p>
 *
 * @author ������
 * @version 1.0
 */
public class Element {
    private int Kind;
    private int Parcentage;
    String[] Kinds = {"���S", "������", "�D�낳", "�ؗ킳", "���킢��", "�₳����", "��܂���",
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
            return Thing+"����������"+this.Kinds[Kind]+"�ŏo���Ă��܂��B\n";
            }else{
                return Thing+"�̔�����"+this.Kinds[Kind]+"�ŏo���Ă��܂��B\n";
            }
        case 100:
            return Thing+"�͂��ׂ�"+this.Kinds[Kind]+"�ŏo���Ă��܂��B\n";
        default:
            return Thing+"��"+Parcentage+"%��"+this.Kinds[Kind]+"�ŏo���Ă��܂��B\n";
        }
    }
}
