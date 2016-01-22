package nicolas.guillot.hellocpp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import nicolas.guillot.hellocpp.core.HelloLib;

public class MainActivity extends AppCompatActivity {

  private EditText mInputView;
  private Button mButton;
  private HelloLib mMyLib;
  private TextView mResultView;

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_main);

    mMyLib = new HelloLib();

    mInputView = (EditText) findViewById(R.id.input_text);
    mButton = (Button) findViewById(R.id.button);
    mResultView = (TextView) findViewById(R.id.result);

    mButton.setOnClickListener(new View.OnClickListener() {
      @Override
      public void onClick(View v) {
        mResultView.setText(mMyLib.sayHello(mInputView.getText().toString()));
      }
    });
  }
}
