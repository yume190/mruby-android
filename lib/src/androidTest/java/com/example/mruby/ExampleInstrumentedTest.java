package com.example.mruby;


import androidx.test.ext.junit.runners.AndroidJUnit4;

import org.junit.Test;
import org.junit.runner.RunWith;

import static org.junit.Assert.*;

import com.yume190.mruby.Lib;


/**
 * Instrumented test, which will execute on an Android device.
 *
 * @see <a href="http://d.android.com/tools/testing">Testing documentation</a>
 */
@RunWith(AndroidJUnit4.class)
public class ExampleInstrumentedTest {
//    @Test
//    public void add() {
//        // Context of the app under test.
//
//        Lib lib = new Lib();
//        assertEquals(3, lib.add(1, 2));
//    }

    @Test
    public void complie2() throws Exception {
        // Context of the app under test.

        String code =
            "sensor_value = Tgm.get_sensor(\"07edv0a1\")\n" +
            "if sensor_value > 8\n" +
            "    Tgm.set_sensor(\"05edr001\", 1)\n" +
            "else\n" +
            "    Tgm.set_sensor(\"05edr001\", 0)\n" +
            "end";

        Byte[] compiled_remove_lv = Lib.compile(code, true);
        Byte[] compiled_lv = Lib.compile(code, false);
        assertEquals(170, compiled_remove_lv.length);
        assertEquals(200, compiled_lv.length);
    }

    @Test
    public void complie3() throws Exception {
        // Context of the app under test.
        String code =
            "sensor_value_01 = Tgm.get_sensor(\"07edv0a2\")\n" +
            "if sensor_value_01 > 5\n" +
            "    Tgm.set_sensor(\"05edr002\", 1)\n" +
            "else\n" +
            "    Tgm.set_sensor(\"05edr002\", 0)\n" +
            "end";

        Byte[] compiled_remove_lv = Lib.compile(code, true);
        Byte[] compiled_lv = Lib.compile(code, false);
        assertEquals(169, compiled_remove_lv.length);
        assertEquals(202, compiled_lv.length);

    }
}

