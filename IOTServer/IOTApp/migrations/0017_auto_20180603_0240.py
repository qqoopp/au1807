# Generated by Django 2.0.5 on 2018-06-02 17:40

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('IOTApp', '0016_tdevice_stautscd'),
    ]

    operations = [
        migrations.RenameField(
            model_name='tdevice',
            old_name='StautsCd',
            new_name='StatusCd',
        ),
    ]
