import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class tryConnect {
    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            //链接数据库
        } catch (ClassNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        try {
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/text?serverTimezone=GMT%2B8", "root", "daisigi1");
//		Statement st=conn.createStatement();
//		String sql="select * from customers ";
//		ResultSet rs= st.executeQuery(sql);
//		while(rs.next()) {
//			System.out.println(rs.getString("cust_name"));
//		}
            System.out.println("连接成功");
            Statement st = conn.createStatement();
            boolean isSucess = st.execute("insert into customers(cust_id,cust_name)values(10007,'李四')");
            if (isSucess) {
                System.out.println("成功增加");
            } else {
                System.out.println("增加失败");
            }
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}
