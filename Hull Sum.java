    import java.util.Scanner;
     
    public class Main{
     
        private static Point topLeft,bottomLeft,bottomRight;
     
        public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);
            int n = scanner.nextInt();
     
            topLeft = new Point(-1000,1000);
            System.out.println(topLeft);
            bottomLeft = new Point(-1000,-1000);
            System.out.println(bottomLeft);
            bottomRight = new Point(1000,-1000);
            System.out.println(bottomRight);
     
            for (int i = 0; i < n - 3; i++) {
                switch (i%3) {
                    case 0:
                        bottomLeft.x += (20 + i);
                        bottomLeft.y += 20;
                        System.out.println(bottomLeft);
                        break;
                    case 1:
                        bottomRight.x -= (40 + i);
                        bottomRight.y += 20;
                        System.out.println(bottomRight);
                        break;
                    case 2:
                        topLeft.x += 20;
                        topLeft.y -= (40 + i);
                        System.out.println(topLeft);
                        break;
                }
            }
        }
     
        static class Point{
            int x,y;
            Point(int x, int y){
                this.x = x;
                this.y = y;
            }
     
            @Override
            public String toString() {
                return "" + x + " " + y + "";
            }
        }
    } 