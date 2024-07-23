#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

// 清空输入缓冲区的函数
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // 清空缓冲区
    }
}

// 清除控制台上从第二行到第 n 行的内容
void clearScreenExceptWelcome(int lines) {
    printf("\033[H"); // Move cursor to the top left corner
    int i;
    for (i = 1; i < lines; i++) {
        printf("\033[K"); // Clear the line
        if (i < lines - 1) {
            printf("\033[B"); // Move cursor down one line
        }
    }
    printf("\033[H"); // Move cursor to the top left corner again
    printf("\033[38;2;57;197;187m欢迎游玩 轻量级狠人杀！\033[0m\n");
}

int main() {
    printf("\033[38;2;57;197;187m欢迎游玩 轻量级狠人杀！\033[0m\n");
    sleep(1);

    while (1) {
        printf("\n\033[38;2;238;134;219m下面开始新一轮游戏\n请按下回车键！\033[0m\n");
        getchar(); // 等待用户按下回车键

        int user_choose;
        srand(time(0));
        user_choose = (rand() % 10) + 1;

        if (user_choose == 1 || user_choose == 3 || user_choose == 4 || user_choose == 10) {
            printf("\033[38;2;255;197;0m您是%d号,您的身份是平民！\033[0m\n", user_choose);
            sleep(2);
            printf("\033[38;2;0;255;0m裁判:天黑请闭眼\033[0m\n======\n");
            sleep(1);
            printf("狠人请睁眼\n======\n");
            sleep(2);
            printf("男巫请睁眼\n======\n");
            sleep(1);
            printf("预言家请睁眼\n======\n");
            sleep(1.5);
            printf("裁判:天亮力！\n");
            printf("\033[38;2;255;0;0m昨晚您没力！\033[0m\n");
            sleep(1);
            printf("新一轮游戏将在2s后开始！\n");
            sleep(2);
        } else if (user_choose == 2 || user_choose == 6 || user_choose == 9) {
            printf("\033[38;2;255;197;0m您是%d号,您的身份是狠人！\033[0m\n", user_choose);
            sleep(2);
            printf("裁判:天黑请闭眼\n======\n狠人请睁眼\n");
            int human;
            printf("选择您要力的人(1~10): ");
            scanf("%d", &human); // 使用%d格式说明符来读取整数
            clearInputBuffer(); // 清空输入缓冲区
            sleep(1);
            printf("您力了\n");
            if (human == 2 || human == 6 || human == 9) {
                sleep(1.5);
                printf("\033[38;2;255;0;0m您没力!(您力了同伴)\033[0m\n");
                printf("新一轮游戏将在2s后开始！\n");
                sleep(2);
            } else {
                if (human < 1 || human > 10) {
                    printf("没有这一角色\n");
                } else {
                    printf("裁判:狠人请闭眼\n");
                    sleep(2);
                    printf("======\n天亮力\n\n======\n");
                    sleep(1);
                    printf("WARNING:那群若知纷纷为您投票!\n\n");
                    char dead[100]; // 增大缓冲区大小
                    printf("请留下遗言: ");
                    fgets(dead, sizeof(dead), stdin); // 使用fgets读取字符串
                    printf("您的遗言是 %s", dead);
                    sleep(0.5);
                    printf("\033[038;2;255;0;0mYou out!\033[0m\n");
                    sleep(0.2);
                    printf("新一轮游戏将在2s后开始！\n");
                    sleep(2);
                }
            }
        } else if (user_choose == 5) {
            printf("\033[38;2;255;197;0m您是%d号,您的身份是男巫！\033[0m\n", user_choose);
            sleep(2);
            printf("裁判:天黑请闭眼！\n");
            sleep(1);
            printf("裁判:狠人请睁眼！\n");
            sleep(1);
            printf("裁判:你算什么男人~\n======\n");
            sleep(1);
            printf("裁判:男巫请睁眼！\n");
            sleep(0.75);
            int save_or_not;
            printf("裁判:刚才6号似力......您要救吗？(救的话输入1,不救输入0)\n");
            scanf("%d", &save_or_not);
            clearInputBuffer(); // 清空输入缓冲区
            int KN2;
            srand(time(0));
            KN2 = (rand() % 3) + 1;
            if (save_or_not == 1) {
                printf("您选择了 救\n");
                sleep(0.88);
                printf("裁判:男巫请闭眼\n");
                sleep(2);
                if (KN2 == 1 || KN2 == 3) {
                    printf("裁判:天亮力！\n昨晚是贫氨液\n");
                    sleep(1);
                    printf("1号:我认为2号和6号是狠人\n");
                    sleep(1);
                    printf("2号:同意,且我认为5号是狠人\n");
                    sleep(1);
                    printf("3号:5号貌似不是狠人,你们慎重选择\n");
                    sleep(1);
                    printf("[INFO]:4号跳过\n");
                    sleep(1);
                    char Helloword[100];
                    printf("You:");
                    fgets(Helloword, sizeof(Helloword), stdin);
                    printf("5号:%s\n", Helloword);
                    sleep(1);
                    printf("6号:9号和2号十分甚至九分是狠人呐\n");
                    sleep(1);
                    printf("7号:我乃预言家也\n");
                    sleep(1);
                    printf("8号:小学生别叫\n");
                    sleep(1);
                    printf("9号:6号一定是狠人！信我！\n");
                    sleep(1);
                    printf("10号:我十分甚至九分滴赞同呐(喜)\n");
                    sleep(1);
                    printf("  =====接下来请投票=====  \n");
                    sleep(0.5);
                    int I_Love_You;
                    printf("请输入您爱人(否)的号码:");
                    scanf("%d", &I_Love_You);
                    clearInputBuffer(); // 清空输入缓冲区
                    printf("\033[38;2;238;134;219m%d号,我爱死你辣!\033[0m\n", I_Love_You);
                    sleep(0.5);
                    printf("💘\n");
                    sleep(0.8);
                    printf("正在等待其他逝玩人员的结果\n");
                    sleep(0.5);
                    printf("  =");
                    sleep(2);
                    printf("==");
                    sleep(0.8);
                    printf("===");
                    sleep(1);
                    printf("====");
                    sleep(1);
                    printf("\n\033[38;2;255;0;0m6号似力!\033[0m\n");
                    sleep(0.8);
                    printf("裁判:天黑请闭眼\n");
                    sleep(1);
                    printf("裁判:");
                } else {
                    printf("\033[38;2;255;0;0m裁判:天亮力!\n昨晚您似了\033[0m\n");
                    sleep(0.85);
                    printf("新一轮游戏将在2s后开始！\n");
                    sleep(2);
                }
            } else {
                printf("你真冷血!\n");
                sleep(1);
                printf("别玩了,结束");
                return 0;
            }
        } else if (user_choose == 7) {
            printf("\033[38;2;255;197;0m您是%d号,您的身份是预言家！\033[0m\n", user_choose);
        } else if (user_choose == 8) {
            printf("您是%d号,您的身份是猎人！\n",user_choose);
        } else {
            printf("您没有身份，因此无法游玩！\n");
        }

        sleep(0.8); // 等待0.8秒
        clearScreenExceptWelcome(30); // 清除除第一行之外的内容（假设屏幕上显示的行数不会超过30行）
    }

    return 0;
}
    
